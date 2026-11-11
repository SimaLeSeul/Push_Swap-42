#!/usr/bin/env python3
"""Exact BFS packer for 42 push_swap.

Stacks are sequences with index 0 at the top.

Target A final layout:
    A = original_A[n:] + sorted(original_A[:n])  # pack at bottom
    B = original_B

Target B final layouts (either is accepted):
    A = original_A[n:]
    B = descending_pack + original_B             # pack at top
or
    A = original_A[n:]
    B = original_B + descending_pack             # pack at bottom

Example:
    ops = pack("B", 6, [4, 6, 3, 1, 2, 5, 11], [-1, -2, -3])
"""

from __future__ import annotations

from collections import defaultdict, deque
import json
import os
from typing import Deque, Dict, Iterable, List, Optional, Sequence, Tuple

from itertools import permutations

DEFAULT_MAX_STATES = 500_000_000
DIR_PATH = os.path.dirname(os.path.realpath(__file__))
print(DIR_PATH)

Operation = str
State = Tuple[Tuple[int, ...], Tuple[int, ...]]

OPERATIONS: Tuple[Operation, ...] = (
    "sa", "sb", "ss", "pa", "pb",
    "ra", "rb", "rr", "rra", "rrb", "rrr",
)

class ForbiddenOperation(ValueError):
    pass


def nested_dict():
	return defaultdict(nested_dict)

def default_nested_dict(iterable):
	return defaultdict(nested_dict, iterable)


def apply_operation(state: State, op: Operation) -> State:
    a, b = list(state[0]), list(state[1])

    def swap(s: List[int]) -> None:
        if len(s) >= 2:
            if not ((1 <= s[0] <= 6) and (1 <= s[1] <= 6)):
            	raise ForbiddenOperation
            s[0], s[1] = s[1], s[0]
        else:
            raise ForbiddenOperation

    def rotate(s: List[int]) -> None:
        if len(s) >= 2:
            elem = s.pop(0)
            if not (1 <= elem <= 6):
                raise ForbiddenOperation
            s.append(elem)
        else:
            raise ForbiddenOperation

    def reverse_rotate(s: List[int]) -> None:
        if len(s) >= 2:
            elem = s.pop()
            if not (1 <= elem <= 6):
                raise ForbiddenOperation
            s.insert(0, elem)
        else:
            raise ForbiddenOperation

    if op == "sa":
        swap(a)
    elif op == "sb":
        swap(b)
    elif op == "ss":
        swap(a)
        swap(b)
    elif op == "pa":
        if not (b and (1 <= b[0] <= 6)):
            raise ForbiddenOperation
        a.insert(0, b.pop(0))
            
    elif op == "pb":
        if not (a and (1 <= a[0] <= 6)):
            raise ForbiddenOperation
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

    return tuple(a), tuple(b)


def _make_goals(target: str, n: int, a: Tuple[int, ...],
                b: Tuple[int, ...]) -> set[State]:
    pack_values = a[:n]
    rest_a = a[n:]

    if target == "A":
        # Sorted ascending from top to bottom, placed after all untouched A items.
        return {(rest_a + tuple(sorted(pack_values)), b)}

    # Sorted descending from top to bottom; contiguous at either end of B.
    descending = tuple(sorted(pack_values, reverse=True))
    return {
        (rest_a, descending + b),
        (rest_a, b + descending),
    }


def pack(
    target_stack: str,
    n: int,
    a: Sequence[int],
    b: Sequence[int] = (),
    *,
    max_states: Optional[int] = DEFAULT_MAX_STATES,
) -> List[Operation]:
    """Find a shortest operation sequence packing the first n elements of A.

    Args:
        target_stack: "A" or "B".
        n: Pack size, from 1 to 6.
        a: Stack A, top element first. Must contain at least n+1 elements.
        b: Stack B, top element first.
        max_states: Search-state limit; use None for an unlimited search.

    Returns:
        A minimum-length list of standard push_swap operations.

    Raises:
        ValueError: Invalid input.
        RuntimeError: Search limit reached or no solution found.
    """
    target = target_stack.upper()
    if target not in ("A", "B"):
        raise ValueError("target_stack must be 'A' or 'B'")
    if not 1 <= n <= 6:
        raise ValueError("n must be between 1 and 6")
    if len(a) < n + 1:
        raise ValueError("A must contain at least n+1 elements")

    original_a, original_b = tuple(a), tuple(b)
    if len(set(original_a + original_b)) != len(original_a) + len(original_b):
        raise ValueError("Values across A and B must be unique")

    start: State = (original_a, original_b)
    goals = _make_goals(target, n, original_a, original_b)
    if start in goals:
        return []

    # Every operation has unit cost. Ordinary BFS therefore returns a
    # globally shortest sequence, using the complete stacks as the state.
    queue: Deque[State] = deque([start])
    parents: Dict[State, List[Operation]] = {start: []}

    while queue:
        state = queue.popleft()
        last_ops = parents[state]

        for op in OPERATIONS:
            try:
                nxt = apply_operation(state, op)
            except ForbiddenOperation:
                continue
            if nxt in parents:
                continue

            if nxt in goals:
                return last_ops + [op]
            parents[nxt] = last_ops + [op]

            if max_states is not None and len(parents) >= max_states:
                raise RuntimeError(
                    f"Reached max_states={max_states:,} before finding a solution. "
                    "Increase the limit or use a more constrained search."
                )
            queue.append(nxt)

    raise RuntimeError("No valid packing sequence exists")


def brute_force():
    data = nested_dict()
    for n in range(1, 6):
        for perm in permutations(range(1, 1 + n)):
            ops = pack("A", n, perm + (11, 12), (13, 14))
            label = "".join(map(str, perm))
            data[f"{n}a"][label] = ",".join(ops)
        print(f"{n}a")

    for n in range(1, 7):
        for perm in permutations(range(1, 1 + n)):
            ops = pack("B", n, perm + (11, 12), (13, 14))
            label = "".join(map(str, perm))
            data[f"{n}b"][label] =  ",".join(ops)
        print(f"{n}b")

    with open(f"{DIR_PATH}/resultsss.json", "w") as file:
        json.dump(data, file)


def apply_operations(
    a: Sequence[int],
    b: Sequence[int],
    operations: Iterable[Operation],
) -> Tuple[List[int], List[int]]:
    """Apply a returned sequence; useful for checking its final layout."""
    state: State = (tuple(a), tuple(b))
    for op in operations:
        state = apply_operation(state, op)
    return list(state[0]), list(state[1])


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description="Find a shortest push_swap packing sequence")
    parser.add_argument("-brute", action="store_true")
    parser.add_argument("target", choices=("A", "B", "a", "b"))
    parser.add_argument("n", type=int, choices=range(1, 7))
    parser.add_argument("--a", nargs="*", type=int, default=[], help="Stack A, top first")
    parser.add_argument("--b", nargs="*", type=int, default=[], help="Stack B, top first")
    parser.add_argument("--max-states", type=int, default=DEFAULT_MAX_STATES)
    args = parser.parse_args()

    if args.brute:
        brute_force()
    else:
        ops = pack(args.target, args.n, args.a, args.b, max_states=args.max_states)
        final_a, final_b = apply_operations(args.a, args.b, ops)
        print(f"{len(ops)} operations:")
        print(" ".join(ops) if ops else "(already packed)")
        print("A:", final_a)
        print("B:", final_b)
