# Lab 03 — Combinatorial Search via SAT Encoding

Finds a maximum complete subgraph (clique) satisfying degree constraints by
encoding the search problem into CNF and handing it to an off-the-shelf SAT
solver, rather than searching the graph directly.

## Approach

From `writeup.txt`: the encoding uses a **sequential counter** (in unary)
to count how many vertices are currently included while ensuring the
included set stays a complete subgraph — clauses forbid including two
non-adjacent vertices together, and forbid vertices whose degree is below
the required threshold. The sequential-counter at-most-k construction
follows Frisch & Giannoros, *SAT Encodings of the At-Most-k Constraint*
(`docs/reference-at-most-k-encoding.pdf`) — the actual paper used as the
basis for the encoding, not just background reading.

## Files

- `part1.cpp` — reads the graph and parameters, generates the CNF encoding.
- `part1_write.cpp` — variant that writes the CNF to a file instead of
  piping it directly to the solver.
- `part2.cpp` — reads back a SAT solver's output and reconstructs/verifies
  the resulting subgraph.
- `testdata/checker.py` — independently verifies a solution is a valid
  complete subgraph via `networkx`.
- `testdata/problem_generator.py` — generates random test graphs
  (`N`, `k1`, `k2` parameters).
- `testdata/test1.graph` … `test3.graph` — sample generated test graphs.

## Run it

```bash
./compile.sh        # builds p1_read, p1_write, p2
./run1.sh <graph>   # p1_read <graph>
./run2.sh <graph>   # p1_write <graph>
./run3.sh <graph>   # p2 <graph>
```

## `archive/`

Earlier/alternate solver attempts kept for reference:
`part1-early-version.cpp`, `part2-early-version.cpp` (an earlier top-level
iteration of the final solver), and `npart2-alt-attempt.cpp`,
`esha2-alt-attempt.cpp` (alternate part-2 approaches).

## Notes

`docs/assignment-brief.pdf` is the assignment spec used for the final
submission; `docs/additional-notes.pdf` is a second, differently-sized
course PDF related to the same assignment, kept since its content differs
from the brief.
