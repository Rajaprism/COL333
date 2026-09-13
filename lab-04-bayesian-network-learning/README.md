# Lab 04 — Bayesian Network Parameter Learning

Learns the conditional probability tables (CPTs) of a Bayesian network from
partially-observed data records, using the classic ALARM network as the
test case.

## What it does

`startip_code.cpp` implements a `BayesNet` class that:
- parses a `.bif`-format network definition (`testdata/alarm.bif`) — nodes,
  parents/children, and (possibly missing) CPT entries,
- reads observed data records (`testdata/records.txt`),
- iteratively estimates the missing CPT parameters from the records within
  a fixed time budget.

`testdata/gold_alarm.bif` is the ground-truth network used for grading;
`testdata/solved_alarm.bif` is a sample learned network produced by a run
of this solver.

## Run it

```bash
./compile.sh                                  # g++ -std=c++11 startip_code.cpp -o my_program
./my_program testdata/alarm.bif testdata/records.txt
```

(`BayesNet(bayesfile, datafile, timeLimit)` — the time limit is hardcoded
to 120s in `main`.)

`Format_Checker.cpp` is the provided tool to validate that a learned
`.bif` file has the right structure before scoring it against the gold
network.

## Notes

`docs/assignment-brief.pdf` is the brief bundled with the final submission.
`docs/assignment-brief-alt1.pdf` and `assignment-brief-alt2.pdf` are two
other PDFs from the original repository with the same filename pattern but
different content/size — kept rather than guessed-and-discarded since it's
unclear which (if any) superseded the others.
