# IoE
## Isles of Eris

This game engine is nothing more than a passion project for me. My intentions are to one day compile this into a game. Until then, the grind for a feature rich, highly modulated, but easily customizable game engine is more than an over-reach — however I am undeterred. Taking my lumps along the way, we press on.

---

## Prerequisites

| Tool | Purpose |
|---|---|
| [g++ / GNU Make](https://chocolatey.org) | C++20 compiler + build system (Windows: install via Chocolatey) |
| [Doxygen](https://www.doxygen.nl/index.html) | HTML documentation generation |
| [GNUPlot](http://www.gnuplot.info) | Frequency chart plotting (audiosuite, Linux only) |
| [VSCode](https://code.visualstudio.com) | Recommended IDE |

Minimum compiler: **C++20**. Tested with MinGW-W64 g++ 13.2 on Windows 11 and GCC on Ubuntu.

---

## Building

```bash
make info          # List all targets
make core          # Compile core engine objects only
make clisuite      # Interactive REPL   -> clisuite.exe
make testsuite     # Test runner        -> testsuite.exe
make audiosuite    # Audio tools        -> audiosuite.exe
make helpsuite     # Dev help CLI       -> helpsuite.exe
make engine        # World server       -> engine.exe
make docs          # Generate Doxygen HTML
make clean         # Remove .o files
make cleanall      # Remove .o files and binaries
```

---

## Suites

### Core Engine
All game logic. Compiled as object files and linked into every suite.
```bash
make core
```

### TestSuite — debugger's delight
Custom unit testing framework. No external test library.
```bash
make testsuite
./testsuite.exe -h       # Show all test cases
./testsuite.exe 0        # Run every test case
./testsuite.exe 16       # Run a single case (strategy module)
```

### CLISuite — interactive shell
REPL for live engine interaction. Spawn actors, run combat, inspect the leaderboard.
```bash
make clisuite
./clisuite.exe 0         # Normal mode
./clisuite.exe 1         # Debug mode
```

**Available commands:**

| Command | Usage | Description |
|---|---|---|
| `help` | `help [command]` | List commands or describe one |
| `spawn` | `spawn <player\|toon> [name] [style]` | Create an actor. Styles: `balanced` `aggressive` `defensive` `berserker` `cowardly` |
| `fight` | `fight <pve\|pvp\|eve>` | Start combat between spawned actors |
| `step` | `step` | Advance combat one cycle and print status |
| `status` | `status` | Print HP, health state, combat state, and strategy for all actors |
| `strategy` | `strategy <p1\|p2\|t1\|t2> <style>` | Swap a live actor's combat strategy |
| `leaderboard` | `leaderboard` | Display all stat leaderboard sections |
| `reset` | `reset` | Delete all spawned actors and clear combat |
| `create` | `create <type> [name]` | Create an item: `sword` `shield` `staff` `ring` `relic` `backpack` |
| `inventory` | `inventory` | List session inventory |
| `name` | `name <count>` | Generate random names |
| `runtime` | `runtime` | Show elapsed session time |
| `reload` | `reload` | Reload `engine.ini` from disk |
| `prompt` | `prompt <symbol>` | Change the shell prompt |

### AudioSuite — sound testing
WAV playback and frequency analysis.
```bash
make audiosuite
./audiosuite.exe -h
```

### HelpSuite — developer reference
CLI documentation for every core module.
```bash
make helpsuite
./helpsuite.exe -h
```

### Engine — World Server
A persistent HTTP REST API server that exposes the game engine. Intended for consumption by the Django frontend.

```bash
make engine
./engine.exe 8081        # Start server on port 8081 (default: 8081)
./engine.exe -h          # Show help
./engine.exe -v          # Show version
```

**Vendored dependencies** (single-header, no install required):
- `engine/httplib.h` — cpp-httplib v0.43.1
- `engine/json.hpp` — nlohmann/json

---

## REST API Reference

Base URL: `http://localhost:8081`

All request bodies are JSON (`Content-Type: application/json`). All responses are JSON.

---

### `GET /health`
Liveness probe. Always returns 200.

**Response:**
```json
{
  "status": "ok",
  "version": "0.5.4",
  "sessions": 2
}
```

---

### `POST /fight`
Start a new combat session. Creates two Toons and returns a session ID used by all subsequent calls.

**Request:**
```json
{
  "t1": "Grix",
  "t2": "Zorr",
  "style1": "berserker",
  "style2": "defensive"
}
```

| Field | Type | Required | Description |
|---|---|---|---|
| `t1` | string | yes | Name for combatant 1 |
| `t2` | string | yes | Name for combatant 2 |
| `style1` | string | no | Combat style for t1 (default: `balanced`) |
| `style2` | string | no | Combat style for t2 (default: `balanced`) |

**Valid styles:** `balanced` `aggressive` `defensive` `berserker` `cowardly`

**Response `201`:**
```json
{
  "session_id": "e0e68e028e129f8d048fe31620d3ee7f",
  "t1": {
    "name": "Grix",
    "hp": 64,
    "health_state": "HEALTHY",
    "combat_state": "FIGHT",
    "strategy": "Berserker"
  },
  "t2": {
    "name": "Zorr",
    "hp": 64,
    "health_state": "HEALTHY",
    "combat_state": "FIGHT",
    "strategy": "Defensive"
  }
}
```

**Nuances:**
- Each call creates a fresh session with new actors — there is no shared actor pool between sessions.
- Sessions are isolated; multiple concurrent sessions are safe.
- Sessions expire after **5 minutes** of inactivity. Expired sessions return `404`.

---

### `POST /step`
Advance an active combat session by exactly one cycle. Call repeatedly until `ended: true`.

**Request:**
```json
{ "session_id": "e0e68e028e129f8d048fe31620d3ee7f" }
```

**Response `200` (combat ongoing):**
```json
{
  "session_id": "e0e68e028e129f8d048fe31620d3ee7f",
  "in_combat": true,
  "ended": false,
  "winner": "",
  "t1": { "name": "Grix", "hp": 52, "health_state": "HEALTHY", "combat_state": "FIGHT", "strategy": "Berserker" },
  "t2": { "name": "Zorr", "hp": 44, "health_state": "HURTING", "combat_state": "FIGHT", "strategy": "Defensive" }
}
```

**Response `200` (combat ended):**
```json
{
  "session_id": "e0e68e028e129f8d048fe31620d3ee7f",
  "in_combat": false,
  "ended": true,
  "winner": "Grix",
  "t1": { "name": "Grix", "hp": 40, "health_state": "HEALTHY", "combat_state": "FIGHT", "strategy": "Berserker" },
  "t2": { "name": "Zorr", "hp": -8, "health_state": "DEAD",    "combat_state": "IDLE",  "strategy": "Defensive" }
}
```

**Nuances:**
- `winner` is the surviving actor's name, or `"fled"` if combat ended by a flee.
- Calling `/step` after `ended: true` is safe — it returns the final state again without advancing.
- On combat end, peak single-hit damage for both actors is automatically submitted to the LeaderBoard.

---

### `GET /status`
Read current actor state without advancing combat.

**With session ID:** `GET /status?session=<session_id>`

**Response `200`:**
```json
{
  "session_id": "e0e68e028e129f8d048fe31620d3ee7f",
  "in_combat": false,
  "ended": true,
  "winner": "Grix",
  "t1": { "name": "Grix", "hp": 40, ... },
  "t2": { "name": "Zorr", "hp": -8, ... }
}
```

**Without session ID:** `GET /status` — returns a summary of all active sessions.

**Response `200`:**
```json
{
  "sessions": [
    { "session_id": "e0e68e02...", "ended": false, "t1": "Grix", "t2": "Zorr" },
    { "session_id": "a1b2c3d4...", "ended": true,  "t1": "Rex",  "t2": "Vex" }
  ]
}
```

---

### `GET /leaderboard`
Triggers a full leaderboard print to the server log. JSON serialization of leaderboard data is planned for a future release.

**Response `200`:**
```json
{ "note": "leaderboard printed to server log" }
```

---

### `POST /reset`
Delete one session or all sessions.

**Delete one session:**
```json
{ "session_id": "e0e68e028e129f8d048fe31620d3ee7f" }
```

**Delete all sessions:**
```json
{}
```

**Response `200` (single):**
```json
{ "reset": "e0e68e028e129f8d048fe31620d3ee7f" }
```

**Response `200` (all):**
```json
{ "reset": "all", "cleared": 3 }
```

**Nuances:**
- Deleting a session immediately frees both actor objects and the Combat object.
- Calling reset on an already-ended session is fine and frees its memory.

---

## Architecture Overview

```
Django Frontend
      │
      │  HTTP/JSON (localhost)
      ▼
engine.exe  (WorldServer)
  ├── POST /fight  → creates CombatSession (owns Toon* t1, Toon* t2, Combat*)
  ├── POST /step   → calls Combat::cycleCombat(), checks flee/death
  ├── GET  /status → reads session state, no side effects
  └── POST /reset  → deletes session, frees actors
      │
      ▼
core/ (singletons)
  ├── ConfigManager  ← docs/engine.ini
  ├── Logger
  ├── LeaderBoard    ← updated on combat end
  └── BalanceController
```

The engine is **stateful by design** — active `Combat` objects live in the server process between `/step` calls. Django's only responsibility is holding the `session_id` and deciding when to call `/step`. All game logic runs inside the engine.

---

## Conceptual Roadmap

1. **Core engine** (current) — actors, combat, strategy, leaderboard, config
2. **World server** (current) — REST API over HTTP, session registry, Django-ready
3. **Django frontend** — player auth, persistent stats, game UI consuming the REST API
4. **WebSockets** — real-time combat updates via Django Channels
5. **WebAssembly** — Emscripten compilation for optional browser-native play
