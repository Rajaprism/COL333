# Lab 02 — Rollerball Minimax Bot (v1)

An AI bot for "Rollerball", a chess-variant game, playing via minimax search
with alpha-beta pruning and a material/positional evaluation function
(`src/engine.cpp`). Built on a provided game-engine scaffold (board
representation, move generation, a websocket server for the UI to talk to
the engine) that the team assignment builds an `Engine` on top of.

## Structure

- `src/engine.cpp` / `engine.hpp` — the bot: `MaxVal`/`MinVal` minimax with
  alpha-beta pruning and piece-value evaluation (king/rook/bishop weights).
- `src/board.cpp`, `server.cpp`, `uciws.cpp`, `rollerball.cpp` — provided
  game engine, board representation and UCI-style websocket server used to
  drive a game between the bot and the web UI.
- `src/bindings.cpp`, `engine_py.cpp`, `setup.py` — optional pybind11
  bindings to drive the engine from Python.
- `web/` — the provided browser UI (vanilla HTML/JS + chess piece assets)
  used to watch/play games against the bot.
- `scripts/` — helper scripts to launch the engine server and UI together.

## Run it

```bash
make rollerball                 # builds bin/rollerball
./scripts/run_servers.sh        # start engine + UI servers
./scripts/run_ui.sh             # open the web UI
```

Building needs the [asio](https://think-async.com/Asio/) (standalone,
header-only) and [websocketpp](https://github.com/zaphoyd/websocketpp)
libraries under `include/` — vendored copies were removed from this repo to
keep it small; download them and drop `asio/`, `asio.hpp`, `websocketpp/`
(and `popl.hpp` if using the CLI arg parser) into `include/` before
building.

## `archive/`

Alternate engine implementations explored during development, none of which
made it into the final submission: `raja-engine-variant.cpp`,
`suryanshu-engine-variant.cpp`, and two early standalone prototypes
(`engine_i_o.cpp`, `preengine.cpp`) written before the full client/server
architecture above existed.

## Notes

`docs/assignment-brief.pdf` is the original spec; `docs/original-submission-readme.md`
is the team's original submission readme (collaborators/discussion credits).
