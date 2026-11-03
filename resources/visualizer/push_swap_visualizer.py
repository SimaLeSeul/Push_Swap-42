#!/usr/bin/env python3
"""
Visualize a 42 push_swap operation log with Manim.

Usage:
    python push_swap_visualizer.py operations.txt --values "4 67 3 87 23"
    python push_swap_visualizer.py operations.txt --values-file numbers.txt

Render:
    manim -pqh push_swap_visualizer.py PushSwapScene

The operation file contains one operation per line (blank lines and comments
starting with # are ignored). Values are the original input values, in order.
"""

from __future__ import annotations

import argparse
import os
import re
import sys
from pathlib import Path
from typing import List, Tuple

from manim import *


# ---------------------------------------------------------------------------
# push_swap model
# ---------------------------------------------------------------------------

Operation = str
Stacks = Tuple[List[int], List[int]]


def inverse_operation(op: Operation) -> Operation:
    """Return the inverse of a push_swap operation."""
    inverses = {
        "sa": "sa", "sb": "sb", "ss": "ss",
        "pa": "pb", "pb": "pa",
        "ra": "rra", "rb": "rrb", "rr": "rrr",
        "rra": "ra", "rrb": "rb", "rrr": "rr",
    }
    try:
        return inverses[op]
    except KeyError:
        raise ValueError(f"Unknown operation: {op!r}")


def apply_operation(a: List[int], b: List[int], op: Operation) -> None:
    """Apply one operation in-place. Index 0 is the top of each stack."""

    def swap(stack: List[int]) -> None:
        if len(stack) >= 2:
            stack[0], stack[1] = stack[1], stack[0]

    def rotate(stack: List[int]) -> None:
        if len(stack) >= 2:
            stack.append(stack.pop(0))

    def reverse_rotate(stack: List[int]) -> None:
        if len(stack) >= 2:
            stack.insert(0, stack.pop())

    if op == "sa":
        swap(a)
    elif op == "sb":
        swap(b)
    elif op == "ss":
        swap(a)
        swap(b)
    elif op == "pa":
        if b:
            a.insert(0, b.pop(0))
    elif op == "pb":
        if a:
            b.insert(0, a.pop(0))
    elif op == "ra":
        rotate(a)
    elif op == "rb":
        rotate(b)
    elif op == "rr":
        rotate(a)
        rotate(b)
    elif op == "rra":
        reverse_rotate(a)
    elif op == "rrb":
        reverse_rotate(b)
    elif op == "rrr":
        reverse_rotate(a)
        reverse_rotate(b)
    else:
        raise ValueError(f"Unknown operation: {op!r}")


def read_operations(path: Path) -> List[Operation]:
    operations: List[Operation] = []
    valid = {
        "sa", "sb", "ss", "pa", "pb",
        "ra", "rb", "rr", "rra", "rrb", "rrr",
    }

    for line_number, line in enumerate(path.read_text().splitlines(), start=1):
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        # Accept either one operation per line or whitespace-separated tokens.
        for op in line.split():
            if op not in valid:
                raise ValueError(
                    f"{path}:{line_number}: invalid operation {op!r}"
                )
            operations.append(op)

    return operations


def parse_values(text: str) -> List[int]:
    try:
        values = [int(token) for token in re.split(r"[\s,]+", text.strip()) if token]
    except ValueError as exc:
        raise argparse.ArgumentTypeError("Values must be integers.") from exc

    if not values:
        raise argparse.ArgumentTypeError("At least one input value is required.")
    if len(values) != len(set(values)):
        raise argparse.ArgumentTypeError("push_swap input values must be unique.")
    return values


def reconstruct_initial_state(sorted_values: List[int],
                              operations: List[Operation]) -> Stacks:
    """Undo the log, starting from the sorted final state."""
    a = sorted(sorted_values)
    b: List[int] = []

    for op in reversed(operations):
        apply_operation(a, b, inverse_operation(op))

    if b:
        raise ValueError(
            "Reversing the operation log did not leave stack B empty. "
            "Check that the values and operation log belong together."
        )
    return a, b


# ---------------------------------------------------------------------------
# Manim scene
# ---------------------------------------------------------------------------

class PushSwapScene(Scene):
    """Animated replay of a push_swap operation log."""

    def setup(self):
        self.operations = read_operations(Path(os.environ["PUSHSWAP_OPS"]))
        self.values = parse_values(os.environ["PUSHSWAP_VALUES"])
        self.initial_a, self.initial_b = reconstruct_initial_state(
            self.values, self.operations
        )

        # Verify that replaying the log actually sorts the supplied values.
        check_a = self.initial_a.copy()
        check_b = self.initial_b.copy()
        for op in self.operations:
            apply_operation(check_a, check_b, op)

        if check_a != sorted(self.values) or check_b:
            raise ValueError(
                "The supplied values and operation log are inconsistent: "
                "replaying the operations does not produce sorted A and empty B."
            )

    def make_stack_view(self, values: List[int], center_x: float,
                        title: str, color, max_width: float) -> VGroup:
        title_mob = Text(title, font_size=30, weight=BOLD)
        title_mob.move_to([center_x, 2.65, 0])

        if not values:
            empty = Text("(empty)", font_size=22, color=GREY_B)
            empty.move_to([center_x, 1.45, 0])
            return VGroup(title_mob, empty)

        count = len(values)
        gap = min(0.07, max(0.008, 0.12 * max_width / count))
        cell_width = min(0.72, (max_width - gap * (count - 1)) / count)
        total_width = count * cell_width + (count - 1) * gap
        start_x = center_x - total_width / 2

        # Bar heights encode relative rank, so large stacks remain readable
        # even when individual numeric labels would be too small to display.
        ordered = sorted(values)
        ranks = {value: rank for rank, value in enumerate(ordered)}
        rank_denominator = max(1, len(ordered) - 1)
        cells = VGroup()

        for index, value in enumerate(values):
            x = start_x + index * (cell_width + gap) + cell_width / 2
            rank = ranks[value] / rank_denominator
            bar_height = 0.28 + 1.35 * rank
            rect = RoundedRectangle(
                width=cell_width,
                height=bar_height,
                corner_radius=min(0.05, cell_width / 5),
                stroke_color=color,
                stroke_width=1 if count > 35 else 2,
                fill_color=color,
                fill_opacity=0.28,
            )
            rect.move_to([x, 0.55 + bar_height / 2, 0])

            parts = [rect]
            if count <= 24:
                font_size = min(22, max(9, 150 / max(1, len(str(value)))))
                label = Text(str(value), font_size=font_size)
                label.move_to(rect.get_center())
                parts.append(label)
            cells.add(VGroup(*parts))

        return VGroup(title_mob, cells)

    def make_state(self, a: List[int], b: List[int]) -> VGroup:
        left = self.make_stack_view(
            a, center_x=-3.25, title=f"A ({len(a)})",
            color=BLUE_C, max_width=6.0
        )
        right = self.make_stack_view(
            b, center_x=3.25, title=f"B ({len(b)})",
            color=ORANGE, max_width=6.0
        )
        return VGroup(left, right)

    def construct(self):
        title = Text("42 — push_swap", font_size=36, weight=BOLD)
        title.to_edge(UP, buff=0.25)
        self.add(title)

        operation_label = Text("Initial state", font_size=24, color=YELLOW)
        operation_label.move_to([0, -2.35, 0])
        self.add(operation_label)

        a = self.initial_a.copy()
        b = self.initial_b.copy()
        state = self.make_state(a, b)
        self.play(FadeIn(state), run_time=0.6)
        self.wait(0.6)

        total = len(self.operations)
        if total == 0:
            operation_label.become(
                Text("No operations", font_size=24, color=GREEN)
                .move_to(operation_label)
            )
        else:
            for index, op in enumerate(self.operations, start=1):
                apply_operation(a, b, op)

                new_label = Text(
                    f"{index}/{total}   {op}",
                    font_size=24,
                    color=YELLOW,
                ).move_to(operation_label)
                new_state = self.make_state(a, b)

                self.play(
                    Transform(state, new_state),
                    Transform(operation_label, new_label),
                    run_time=0.28,
                )

            final_label = Text(
                f"Sorted!  ({total} operations)",
                font_size=26,
                color=GREEN,
            ).move_to(operation_label)
            self.play(Transform(operation_label, final_label), run_time=0.4)

        self.wait(2)


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Create a Manim animation of a 42 push_swap operation log."
    )
    parser.add_argument("operations", type=Path, help="File containing operations")
    values_group = parser.add_mutually_exclusive_group(required=True)
    values_group.add_argument(
        "--values",
        help='Original values, e.g. "4 67 3 87 23" (commas also accepted)',
    )
    values_group.add_argument(
        "--values-file",
        type=Path,
        help="Text file containing the original values",
    )
    parser.add_argument(
        "--quality",
        choices=("l", "m", "h", "p", "k"),
        default="h",
        help="Manim quality: l, m, h, p, k (default: h)",
    )
    parser.add_argument(
        "--preview",
        action="store_true",
        help="Open the rendered video when rendering finishes",
    )
    args = parser.parse_args()

    if not args.operations.is_file():
        parser.error(f"Operations file not found: {args.operations}")

    if args.values_file:
        if not args.values_file.is_file():
            parser.error(f"Values file not found: {args.values_file}")
        raw_values = args.values_file.read_text()
    else:
        raw_values = args.values

    try:
        values = parse_values(raw_values)
        operations = read_operations(args.operations)
        reconstruct_initial_state(values, operations)
    except (ValueError, argparse.ArgumentTypeError) as exc:
        parser.error(str(exc))

    # Pass input to the Manim Scene through environment variables. Manim's
    # CLI remains responsible for rendering and output-file management.
    os.environ["PUSHSWAP_OPS"] = str(args.operations.resolve())
    os.environ["PUSHSWAP_VALUES"] = " ".join(map(str, values))

    from manim.__main__ import main as manim_main

    sys.argv = [
        "manim",
        "-p" if args.preview else "",
        f"-q{args.quality}",
        str(Path(__file__).resolve()),
        "PushSwapScene",
    ]
    sys.argv = [arg for arg in sys.argv if arg]
    manim_main()


if __name__ == "__main__":
    main()
