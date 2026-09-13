# Lab 01 — Greedy Hill Climbing (Sports Zone Layout)

Assigns a set of "zones" to locations to minimize total layout cost, using
greedy hill climbing with random restarts to escape local optima.

## Approach

From `writeup.txt`: starting from a randomly generated permutation (best of
several random draws), the solver repeatedly tries all pairwise swaps of
zone locations and takes any swap that improves the cost — classic hill
climbing. Once no swap improves the current state (a local optimum), it
restarts from a new random initial state and keeps the best mapping found
across all restarts.

## Files

- `main.cpp` / `SportsLayout.cpp` / `SportsLayout.h` — the solver.
- `writeup.txt` — the submitted explanation of the algorithm.
- `docs/assignment-brief.pdf` — original assignment spec.
- `testdata/` — two independent sample-input sets (`test_cases/`, `tests/`)
  with expected outputs, used to validate the solver during development.

## Run it

```bash
./compile.sh          # g++ -std=c++11 -o main main.cpp SportsLayout.cpp
./run.sh <input> <output>
```

## `archive/`

- `early-version/` — an earlier snapshot of the same solver (differs from
  the final version above but has no accompanying writeup).
- `dev-iterations/` — intermediate iterations of the algorithm
  (`new.cpp`, `previous_final.cpp`, `update1.cpp`, `f1.cpp`) kept to show
  the progression from the starter code to the final approach.
