*This project has been created as part of the 42 curriculum by mibaboul, jecourto.*

# Push_swap

## Description

Push_swap is a C project that sorts distinct integers using two stacks and a
restricted set of operations. The program receives the initial contents of stack
`a` and prints the instructions needed to sort it in ascending order. Stack `b`
starts empty and provides temporary storage. At the end, the smallest value must
be at the top of `a`, and `b` must be empty.

The program provides four strategies: minimum extraction (`--simple`), Fibonacci
pack merging (`--medium`), binary radix sorting (`--complex`), and automatic
selection based on initial disorder (`--adaptive`, the default). Their complexity
is measured in **Push_swap operations**, as required by [the subject](subject.pdf).

## Instructions

### Compilation

Build from the repository root with a C compiler (`cc`) and `make`:

```sh
make
```

The Makefile builds the included Libft and links the `push_swap` executable with
`-Wall -Wextra -Werror`. No separate installation is needed.

| Command | Effect |
| --- | --- |
| `make` or `make all` | Build the executable. |
| `make bonus` | Build the bonus `checker` executable. |
| `make clean` | Remove project and Libft object files. |
| `make fclean` | Also remove the executable and Libft archive. |
| `make re` | Clean everything and rebuild. |

### Running the program

The first integer is the top of stack `a`. Integers can be separate arguments,
grouped inside a quoted argument, or a mixture of both:

```sh
./push_swap --simple 3 1 2
./push_swap --complex "4 1 3 2"
./push_swap --complex "4 1" 3 2
./push_swap --simple -3 +2 0 -1
```

| Option | Effect |
| --- | --- |
| `--simple` | Force minimum extraction, with an O(n²) operation bound. |
| `--medium` | Force Fibonacci pack merging, within the O(n√n) operation target. |
| `--complex` | Force binary radix sorting, with an O(n log n) operation bound. |
| `--adaptive` | Select a method from the initial disorder; this is the default. |
| `--bench` | Add statistics on standard error after sorting. |

Use at most one strategy selector per invocation. Options are separate arguments
and may appear before or after the integers. `--bench` can accompany any strategy.
For example:

```sh
./push_swap 3 1 2
./push_swap --adaptive --bench "4 1 3 2"
./push_swap --medium "4 1 3 2"
```

Instructions go to **standard output**, one per line. For example:

```sh
./push_swap --simple 3 1 2
```

```text
ra
pb
pb
pb
pa
pa
pa
```

To count instructions or save them:

```sh
./push_swap --complex "4 1 3 2" | wc -l
./push_swap --complex "4 1 3 2" > operations.txt
```

The first command reports `12`.

### Input validation

Each value must be a signed decimal integer in the range
`-2147483648` to `2147483647`. Optional `+` or `-` signs and leading zeros are
accepted. Duplicate detection compares numeric values, so `1` and `+01` are
duplicates. Whitespace can separate numbers inside an argument.

Invalid input prints exactly `Error` followed by a newline to standard error and
exits with a failure status. Examples include:

```sh
./push_swap --simple 3 2 3          # Duplicate value
./push_swap --complex 2147483648   # Outside the int range
./push_swap --simple 0 one 2       # Invalid integer
./push_swap --simple ""           # Empty argument
./push_swap --unknown 1 2          # Unknown option
./push_swap --simple --complex 2 1 # Multiple strategy selectors
```

Calling `./push_swap` without arguments produces no output. With any strategy,
an already sorted input or a single integer produces no operations. Recognized
options without integers are accepted as an empty stack; `--bench` then reports
zero disorder and zero operations. Empty or whitespace-only integer arguments
are rejected.

### Benchmark and checker

`--bench` reports the initial disorder as a percentage with two decimal places,
the selected strategy and its operation complexity, the total instruction count,
and the count of each of the eleven operation types. The instruction stream stays
on standard output; statistics go to standard error.

```sh
./push_swap --complex --bench "4 1 3 2" > /dev/null
```

```text
[bench] disorder :66.67%
[bench] strategy :Complex | O(n*log(n))
[bench] total operations : 12
[bench] sa : 0 sb : 0 ss : 0 pa : 4 pb : 4
[bench] ra : 4 rb : 0 rr : 0 rra : 0 rrb : 0 rrr : 0
```

To keep both streams separately:

```sh
./push_swap --complex --bench "4 1 3 2" > operations.txt 2> bench.txt
```

Build the bonus checker and give it the same initial integers as `push_swap`:

```sh
make bonus
./push_swap --complex --bench "4 1 3 2" 2> bench.txt | ./checker "4 1 3 2"
```

The result is `OK` when `a` is sorted and `b` is empty, or `KO` otherwise.
The checker reads the eleven supported instructions from standard input until
EOF, with a newline after each instruction. Invalid integers or instructions
print `Error` to standard error. It accepts integers only, without strategy or
benchmark options. With no arguments it exits silently. Its dedicated sources
are `checker_bonus.c`, `checker_ops_bonus.c`, and `checker_bonus.h`.

## Stack model and operations

Throughout the examples, stacks are written **from top to bottom, left to right**:
`[3, 1, 2]` means that `3` is the top element. `[]` means an empty stack.

### Circular doubly linked lists

Each stack stores its top pointer and size. Each node contains an integer value,
a rank used by radix sorting, and `next` and `prev` pointers.

```text
                   top
                    |
                    v
              [3] <--> [1] <--> [2]
               ^                 |
               +------ next -----+

    next: 3 -> 1 -> 2 -> 3
    prev: 3 -> 2 -> 1 -> 3
```

The tail is `top->prev`, and the head after a forward rotation is `top->next`.
For one node, both links point to that node; an empty stack has a null top.
Rotations move the top pointer, and pushes detach and relink an existing node.
These operations take O(1) CPU time each and require no new node allocation.

### Available instructions

| Instruction | Effect |
| --- | --- |
| `sa` | Swap the first two values in `a`. |
| `sb` | Swap the first two values in `b`. |
| `ss` | Perform `sa` and `sb` together. |
| `pa` | Move the top of `b` to the top of `a`. |
| `pb` | Move the top of `a` to the top of `b`. |
| `ra` | Move the top of `a` to its bottom. |
| `rb` | Move the top of `b` to its bottom. |
| `rr` | Perform `ra` and `rb` together. |
| `rra` | Move the bottom of `a` to its top. |
| `rrb` | Move the bottom of `b` to its top. |
| `rrr` | Perform `rra` and `rrb` together. |

A swap or rotation leaves a stack with fewer than two elements unchanged. A push
from an empty source leaves both stacks unchanged. A combined instruction counts
as **one emitted operation**, even though it affects both stacks.

## Algorithms

### Simple sort: minimum extraction

Implementation: [simple_sort.c](simple_sort.c).

This adaptation of selection sort repeatedly removes the smallest remaining
value from `a`. It provides a straightforward baseline whose steps are easy to
trace and whose operation count has a quadratic upper bound.

1. Return immediately if `a` is already sorted and `b` is empty.
2. Scan `a` to find the minimum and its zero-based position `p`.
3. Bring it to the top using the shorter rotation direction. For a stack of size
   `k`, use `p` rotations with `ra` when `p <= k / 2`; otherwise use `k - p`
   reverse rotations with `rra`. Ties use `ra`.
4. Execute `pb`, then repeat until `a` is empty.
5. Execute `pa` until `b` is empty.

```text
Find minimum in a
        |
        v
Choose shorter path: ra or rra
        |
        v
pb: place minimum on b ----> repeat while a is not empty
        |
        v
pa: return every element to a
```

For example, in `[4, 3, 2, 1, 5]`, the minimum has position `3`. Two `rra`
operations bring it to the top, instead of three `ra` operations.

#### Complete example: `3 1 2`

| Step | Instruction | Stack `a` | Stack `b` |
| --- | --- | --- | --- |
| Initial | — | `[3, 1, 2]` | `[]` |
| 1 | `ra` | `[1, 2, 3]` | `[]` |
| 2 | `pb` | `[2, 3]` | `[1]` |
| 3 | `pb` | `[3]` | `[2, 1]` |
| 4 | `pb` | `[]` | `[3, 2, 1]` |
| 5 | `pa` | `[3]` | `[2, 1]` |
| 6 | `pa` | `[2, 3]` | `[1]` |
| 7 | `pa` | `[1, 2, 3]` | `[]` |

Each extracted minimum is larger than the previous one. Since `pb` puts the new
minimum on top of `b`, that stack becomes descending from top to bottom. Returning
its elements with `pa` reverses their order, leaving `a` ascending and `b` empty.

#### Complexity

At size `k`, bringing the minimum to the top requires at most `floor(k / 2)`
rotations. There are exactly `n` pushes to `b` and `n` pushes back to `a` for an
input that enters the extraction loop:

```text
operations <= sum(k = 1..n, floor(k / 2)) + 2n
           = floor(n² / 4) + 2n
           = O(n²)
```

Finding each minimum also scans the remaining nodes, giving O(n²) CPU work for
the sorting routine. It uses O(1) auxiliary memory beyond the O(n) nodes shared
between the two stacks. Already sorted input produces zero operations.

### Complex sort: binary LSD radix

Implementation: [complex_sort.c](complex_sort.c).

Radix sorting groups values by successive bits, starting with the least
significant bit (LSD). Normalizing the input to ranks makes the number of passes
depend on the number of elements, while supporting negative and positive input
values uniformly.

#### 1. Convert values to ranks

The rank of a value is the number of input values smaller than it. Because values
are distinct, ranks range from `0` to `n - 1` and preserve the original ordering.
The integer values stay in the nodes; the algorithm stores ranks separately.

For input `4 1 3 2`:

| Original value | Rank | Binary rank (`bit 1`, `bit 0`) |
| --- | --- | --- |
| `4` | `3` | `11` |
| `1` | `0` | `00` |
| `3` | `2` | `10` |
| `2` | `1` | `01` |

The same rule maps `[-10, 42, 0]` to ranks `[0, 2, 1]`. Sorting those ranks also
sorts the original signed values.

The current `set_rank` implementation compares every value with every node. This
preparation takes O(n²) CPU time and generates no Push_swap instructions.

#### 2. Distribute one bit, then restore

For each bit, starting at bit `0`, remember the initial size of `a` and process
exactly that many elements:

- If the current top rank has a `0` at that bit, execute `pb`.
- If it has a `1`, execute `ra`.
- Once all initial elements have been processed, execute `pa` until `b` is empty.

Using the initial size as the loop bound ensures that rotated elements are not
processed twice during the same pass. Repeat for every bit needed to represent
the largest rank, `n - 1`.

```mermaid
flowchart TD
    S[Assign ranks and count bits] --> B[Start next bit with n elements to process]
    B --> Q{Elements left in this pass?}
    Q -->|Yes| T{Current rank bit is zero?}
    T -->|Yes| P[pb]
    T -->|No| R[ra]
    P --> D[Decrease remaining count]
    R --> D
    D --> Q
    Q -->|No| A[pa until b is empty]
    A --> M{Another bit?}
    M -->|Yes| B
    M -->|No| E[a sorted, b empty]
```

#### Complete example: `4 1 3 2`

The table shows the **original values**; decisions use their ranks from the table
above. Two bits are enough for ranks `0` through `3`.

| Phase | Instruction | Stack `a` | Stack `b` |
| --- | --- | --- | --- |
| Initial | — | `[4, 1, 3, 2]` | `[]` |
| Bit 0 | `ra` | `[1, 3, 2, 4]` | `[]` |
| Bit 0 | `pb` | `[3, 2, 4]` | `[1]` |
| Bit 0 | `pb` | `[2, 4]` | `[3, 1]` |
| Bit 0 | `ra` | `[4, 2]` | `[3, 1]` |
| Restore | `pa` | `[3, 4, 2]` | `[1]` |
| Restore | `pa` | `[1, 3, 4, 2]` | `[]` |
| Bit 1 | `pb` | `[3, 4, 2]` | `[1]` |
| Bit 1 | `ra` | `[4, 2, 3]` | `[1]` |
| Bit 1 | `ra` | `[2, 3, 4]` | `[1]` |
| Bit 1 | `pb` | `[3, 4]` | `[2, 1]` |
| Restore | `pa` | `[2, 3, 4]` | `[1]` |
| Restore | `pa` | `[1, 2, 3, 4]` | `[]` |

This produces twelve operations: four `ra`, four `pb`, and four `pa`.

#### Why successive passes sort the stack

Each pass places the zero-bit group before the one-bit group and preserves the
previous order within each group. The ones remain in order through rotations.
The zeros are reversed by `pb` and reversed again by `pa`, restoring their order.

After bit `0`, ranks are sorted by their lowest bit. After bit `1`, they are sorted
by their lowest two bits, because the second pass preserves the order established
inside each group. Repeating this argument through the highest bit sorts all
ranks, and therefore all original values. Every pass finishes with `b` empty.

#### Complexity

For `n >= 2`, the number of passes is `ceil(log2(n))`. A pass emits exactly `n`
distribution operations (`pb` or `ra`) and at most `n` restoration operations
(`pa`):

```text
operations <= 2n * ceil(log2(n)) = O(n log n)
```

This bound concerns **emitted operations**. The current rank calculation takes
O(n²) CPU time, so the complete sorting routine has O(n²) CPU time despite its
O(n log n) instruction bound. It uses O(1) auxiliary memory beyond the O(n) stack
nodes, including their rank fields. Sorted input and inputs smaller than two
elements return before rank calculation and emit no operations.

### Medium sort: Fibonacci pack merging

Implementation: [medium_sort.c](medium_sort.c), [merge_packs.c](merge_packs.c)
and [pack_utils/](pack_utils/). Select it with `--medium`. An already sorted
stack returns immediately. For fewer than 17 elements, this method uses minimum
extraction to avoid setting up pack lists for small inputs. This fixed-size
fallback does not change the asymptotic operation bound.

The push-swap adaptation of the merge-sort algorithm relies on two main techniques:
- **Packing** the initial data into small sorted chunks, those chunks being distributed in both stacks,
- **Merging** a pack from one stack to a pack in the other stack, keeping the resulting pack sorted, and repeated the process until there is only one sorted pack in stack A.

#### Packing

We use here a hard-coded approach to either:
- Sort the up-to-5 first elements in stack A, making a pack at the bottom of A.
- Make packs of size up-to-6 in stack B ; the resulting pack may end up either at the top or bottom of B.

**Important:** for optimization purposes, the packs in B end reverse-sorted.

Both processes use a pre-computed and hardcoded minimal list of 5 to 12 operations to make the desired pack.

This step costs a total of $n$ to $\frac{5n}{2}$ operations, where $n$ is the total number of elements.

#### Optimal number and size of packs

To prepare efficient merging, we ensure that after the packing step,
the number of packs in each stack are consecutive Fibonacci numbers $F_m$ and $F_{m+1}$.

Also, we try to have the size ratio between packs of B and packs of A as close as possible
to the golden number $\varphi = \dfrac{1 + \sqrt{5}}{2}$. This is achievable with packs of size close to 6 in B, and close to 4 in A.

<img src="resources/Packing.svg">

#### Merging two packs

For each merge, the *source pack* must be at the top of one stack, and the *target pack* must be at the bottom of the **other** stack.

We then insert the source elements with push operations, reverse-rotating the target elements to make the insertions at the right position.

Each merge costs a number of operations equal to the combined size of the merged packs.

<img src="resources/Merging.svg">

#### Merging Fibonacci stacks

Notice that after merging two packs, the resulting pack ends at the bottom of the target stack, which forces us to either:
- Merge the resulting pack immediately (not efficient: as in the classical merge sort, we want to merge packs of similar size to minimize the total cost)
- Waste rotate operations to pick optimal stacks to merge
- Continue merging to the same stack

We pick the third option, which explains the use of Fibonacci numbers:

**Invariant:**
- **Pre:**
	- One stack has $F_{m+1}$ packs of size close to $s$
	- The other stack has $F_{m+2}$ packs of size close to $\varphi s$
- **Post:** After merging $F_{m+1}$ packs from the larger stack to the smaller stack:
	- The target stack ends with $F_{m+1}$ packs of size $(\varphi + 1)s$
	- The source stack ends with $F_{m+2} - F_{m+1} = F_m$ packs of size $\varphi s$

Since $\frac{\varphi + 1}{\varphi} = \varphi$, the pack size ratios are also preserved, and we can now switch the roles of source and target, and repeat until the stacks have only $F_2 = F_1 = 1$ pack each.

Then we perform a last merge to stack A, and the stack is sorted.

#### Complexity

The total number of operations to sort $n$ elements with this algorithm is at most $\frac{5n}{2}$ for packing, plus at most $n$ for each of the $F^{-1}(n)$ stack merges, where $F^{-1}(n)$ is the inverse Fibonacci function, defined as

$$ F^{-1}(n) = \min \{ m \in \mathbf{N} | n \leq F(m) \}$$

The complexity class of this algorithm is thus $O(\frac{5n}{2} + nF^{-1}(n)) = O(n\log_\varphi(n))$.

The pack lists store O(n) metadata nodes. Ranking each initial pack and splitting
its instruction string use bounded temporary space because packs contain at most
six elements. Each merging round processes at most n elements, and there are
O(log n) rounds. The sorting routine therefore uses O(n log n) CPU work and O(n)
auxiliary space beyond the integer nodes. Its O(n log n) operation bound also
satisfies the subject's O(n√n) upper bound for `--medium`.

### Initial disorder

Before any stack operation, `calculate_disorder` counts inversions: pairs of
positions `i < j` for which `a[i] > a[j]`.

```text
total_pairs = n * (n - 1) / 2
disorder    = inversions / total_pairs
```

For fewer than two elements, the result is defined as `0`. An ascending stack has
disorder `0`; a descending stack has disorder `1`.

For `[4, 1, 3, 2]`, the inversions are `(4, 1)`, `(4, 3)`, `(4, 2)`, and `(3, 2)`.
There are six possible pairs, so the initial disorder is `4 / 6`, displayed as
`66.67%` in benchmark mode. This is a measure of pairwise order, not the percentage
of elements outside their final positions.

The current implementation examines every pair in O(n²) CPU time with O(1)
auxiliary memory. These comparisons emit no instructions. Input parsing also
performs duplicate checks against previously stored values, which can require
O(n²) comparisons overall.

### Adaptive strategy

Implementation: [main.c](main.c), `execute`. Use `--adaptive` or omit the selector.
The disorder is computed once on the original stack, before any operation.

| Initial disorder `d` | Selected method | Required operation bound | Auxiliary memory beyond stack nodes |
| --- | --- | --- | --- |
| `0 <= d < 0.2` | Minimum extraction | O(n²) | O(1) |
| `0.2 <= d < 0.5` | Fibonacci pack merging | O(n√n) | O(n) |
| `0.5 <= d <= 1` | Binary radix | O(n log n) | O(1) |

The thresholds `0.2` and `0.5` are prescribed by the subject. Minimum extraction
provides a simple baseline in the low-disorder regime, with constant auxiliary
space and no pack allocation or rank preparation. The middle regime uses sorted
packs and merges to reduce the instruction cost. The high-disorder regime uses
radix, whose operation bound depends on the rank bits and input size rather than
the initial permutation. These choices meet the required bounds; the thresholds
do not guarantee the smallest operation count on every input. In particular,
few inversions do not guarantee few rotations in minimum extraction.

At exactly `d = 0.2`, merging is selected; at exactly `d = 0.5`, radix is selected.
Merging's fallback for fewer than 17 elements also applies through adaptive.
An already sorted stack has `d = 0` and produces no operations.

The bounds follow from the individual methods: at most `floor(n² / 4) + 2n`
operations for extraction, O(n log n) for Fibonacci merging (also O(n√n)), and
at most `2n * ceil(log2(n))` for radix. Selecting a method emits no operations
and adds O(1) space. Only the middle regime allocates O(n) pack metadata; all
regimes share O(n) storage for integer nodes. Initial disorder calculation costs
O(n²) CPU work and O(1) auxiliary space, separate from generated operations.

With `--bench`, adaptive is reported as `Adaptive` with the complexity class of
its selected regime. Forced `--medium` reports `O(n*sqrt(n))`, the required upper
bound, although its merging implementation has the tighter O(n log n) bound.

### Complexity comparison

| Documented strategy | Generated operations, upper bound | CPU time including rank preparation | Auxiliary memory beyond stack nodes |
| --- | --- | --- | --- |
| Simple: minimum extraction | O(n²) | O(n²) | O(1) |
| Binary radix | O(n log n) | O(n²) | O(1) |
| Merge sort | O(n log n) | O(n log n) | O(n) |

All methods share O(n) storage for the integer nodes. Parsing and initial
disorder computation are additional preparation steps. The instruction bounds
describe these implementations; they do not guarantee the shortest possible
sequence for every input.

### Benchmarks

The following results were checked on 17 November 2026. Random inputs contain
distinct signed 32-bit integers, with seed `422026` and 100 samples per size.
Ranges are the minimum and maximum numbers of emitted operations.

| Input | Minimum extraction | Binary radix | Fibonacci merging | Adaptive |
| --- | --- | --- | --- | --- |
| 100 random numbers | 1 207–1 693 | 1 084 | 611–644 | 613–1 084 |
| 500 random numbers | 30 200–34 902 | 6 784 | 4 508–4 585 | 4 526–6 784 |
| 500 sorted numbers | 0 | 0 | 0 | 0 |

The subject requires fewer than 2 000 operations for 100 random numbers and
12 000 for 500. Adaptive passes these limits on this sample and also meets the
good-performance targets of fewer than 1 500 and 8 000 respectively. The forced
simple baseline is shown separately; its quadratic instruction cost can exceed
these limits. These measurements do not prove the same counts for every input.

## Contributors

| Learner | Contributions covered by this README |
| --- | --- |
| `mibaboul` | Simple minimum-extraction sort and complex binary radix sort, implementation of `ft_printf`, shared work on parsing and common project components. |
| `jecourto` | Adaptation of merge sort and packing, shared work on parsing and common project components. |

## Resources

- [Project subject](subject.pdf): stack rules, operation complexity model,
  benchmark format, and evaluation requirements.
- [NIST — Selection sort](https://xlinux.nist.gov/dads/HTML/selectionSort.html):
  background on repeatedly selecting the smallest remaining element. The stack
  adaptation and its instruction bound are explained above.
- [NIST — Radix sort](https://xlinux.nist.gov/dads/HTML/radixsort.html):
  background on successive digit passes and preservation of group order.

### Use of AI

AI assisted with research into algorithmic concepts, test preparation and
verification, and the preparation of this README, including explanations,
diagrams, and command examples. For this documentation, the existing C code was
examined and the illustrated command outputs were checked against the executable.
