# Lab 05 — Rollerball Minimax Bot (v2)

A second iteration of the Rollerball game bot (see
[lab-02](../lab-02-rollerball-minimax-bot)), this time implementing just the
`Engine` against a fixed interface (`engine_base.hpp`) provided by the
course, plus an upgraded Vue.js frontend alongside the original web UI.

## Structure

- `src/engine.cpp` / `engine.hpp` — the bot: a minimax search over a
  `RollerBoard` game-tree wrapper, implementing `Engine::find_best_move`
  from the provided `AbstractEngine` interface.
- `src/board.cpp`, `bdata.cpp`, `butils.cpp` — provided board
  representation/move-generation utilities the engine is built on.
- `src/server.cpp`, `uciws.cpp`, `rollerball.cpp` — provided websocket
  server driving a game between the bot and a UI.
- `web/` — the built browser UI (same origin as lab-02's).
- `websrc/` — a from-scratch Vue 3 + Vite frontend for the same game
  server, as an alternative to `web/`.
- `scripts/` — helper scripts to launch the engine server and UI together.

## Run it

```bash
make rollerball                 # builds bin/rollerball
./scripts/run_servers.sh        # start the engine + UI servers
./scripts/run_ui.sh             # open the (pre-built) web UI
# or, for the Vue frontend:
cd websrc && npm install && npm run dev
```

Building needs the [asio](https://think-async.com/Asio/) (standalone,
header-only) and [websocketpp](https://github.com/zaphoyd/websocketpp)
libraries under `include/` — vendored copies were removed from this repo;
download them and drop `asio/`, `asio.hpp`, `websocketpp/` (and `popl.hpp`
if used) into `include/` before building.

## `archive/`

- `7_3raja.cpp`, `changed.cpp`, `final.cpp`, `fv2.cpp`, `sagar.cpp`,
  `shivam.cpp`, `surya.cpp`, `v1.cpp`, `yfinal.cpp` — alternate engine
  implementations explored during development (named after whoever wrote
  that attempt); none of these are wired into the `Makefile` build.
- `alt-team-engine.cpp` / `.hpp` — a substantially different engine
  implementation found alongside this assignment in the original
  repository, under a different pair of roll numbers
  (`docs/alt-team-submission-readme.md`). Kept for reference rather than
  discarded, since it's a genuinely different implementation and not a
  duplicate of the engine above.

## Notes

The original repository had two different readmes listing different team
members for this assignment (one at the assignment root, one inside the
roll-number-named submission folder) — preserved as-is in
`docs/alt-team-submission-readme.md` rather than reconciled, since it's
unclear which reflects the actual final team.
