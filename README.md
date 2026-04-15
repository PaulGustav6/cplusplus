# TicTacToe — C++17 + SFML

## Overview
A 3×3 TicTacToe game written in C++17. Rendering, input, and windowing use SFML 3. SFML is fetched automatically at build time via CMake FetchContent.

## Tech Stack
- **Language:** C++17
- **Rendering / Windowing:** SFML 3.0.2
- **Build System:** CMake + Ninja (FetchContent for SFML)

## Project Structure
```
src/
  Board.h / Board.cpp   -- 3x3 board, winner detection
  Game.h  / Game.cpp    -- turn management, game state
  main.cpp              -- SFML window, event loop, rendering
assets/
  OpenSans-Regular.ttf  -- font (SIL OFL)
  OFL.txt               -- font licence
CMakeLists.txt          -- build configuration
```

## Build & Run
```bash
# Replit: press Run
# Local:
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/bin/tictactoe
```

## Controls
- Left click — place mark (X / O)
- R — reset
- ESC / close window — quit

## Third-Party Components
- SFML 3.0.2
- OpenSans-Regular.ttf
- SIL Open Font License (OFL) — see `assets/OFL.txt`
