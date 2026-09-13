# AI Search & Reasoning Labs

Five assignments from an undergraduate Artificial Intelligence course
(IIT Delhi, COL333), each implementing a different classical AI technique
end-to-end in C++.

| Lab | Topic | Techniques |
|---|---|---|
| [lab-01-greedy-hill-climbing](lab-01-greedy-hill-climbing) | Zone layout optimization | Greedy hill climbing, random restarts, local search |
| [lab-02-rollerball-minimax-bot](lab-02-rollerball-minimax-bot) | Game-playing AI (v1) | Minimax, alpha-beta pruning, position evaluation |
| [lab-03-sat-clique-search](lab-03-sat-clique-search) | Combinatorial search via SAT | CNF encoding, sequential-counter at-most-k constraints |
| [lab-04-bayesian-network-learning](lab-04-bayesian-network-learning) | Probabilistic reasoning | Bayesian network parameter learning from data |
| [lab-05-rollerball-bot-v2](lab-05-rollerball-bot-v2) | Game-playing AI (v2) | Minimax search against a provided game engine interface |

Each lab folder is self-contained (own `docs/` with the assignment brief,
own README). Labs 1, 3 and 4 were solved individually; labs 2 and 5 were
team assignments — original team writeups/readmes are preserved under each
lab's `docs/`.

## Structure

```
lab-XX-name/
├── README.md      # what it does, how to run it
├── *.cpp / *.hpp  # the submitted implementation
├── archive/       # alternate/earlier engine attempts, kept for reference
├── docs/          # assignment brief + original team writeup
└── testdata/      # sample inputs used to test/run the solution
```

## Repository history

This repo was originally a flat dump of `A1`–`A5` folders with nested
duplicate copies, checked-in `.zip` archives and compiled binaries, and a
full vendored copy of the [asio](https://think-async.com/Asio/) and
[websocketpp](https://github.com/zaphoyd/websocketpp) C++ libraries used by
the two game-bot assignments (labs 2 and 5). It's been reorganized into the
structure above; vendored third-party libraries were removed rather than
committed — see each lab's README for what to fetch before building.
