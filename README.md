# TicTacToe — C++17 + SFML

A simple 3×3 TicTacToe game written in C++17. Rendering, input, and windowing are handled by SFML. Built with CMake.

## Features

- Two-player local (X starts)
- Left-click to place a mark
- Win detection: rows, columns, and diagonals
- Draw detection when the board is full
- Reset and quit via keyboard

## Controls

| Key / Action     | Effect        |
|------------------|---------------|
| Left mouse click | Place mark    |
| R                | Reset game    |
| ESC              | Quit          |
| Window close (×) | Quit          |

## Build & Run

### In Replit

Press the **Run** button. Replit builds the project with CMake and starts the game automatically.

### Local (Linux / macOS)

Requirements: CMake ≥ 3.20, a C++17 compiler, Git.

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/bin/tictactoe
```

Assets are copied to `build/bin/assets/` automatically after the build.

## Assets / Licence

Font: **Open Sans Regular** by Google Fonts contributors.  
Licence: SIL Open Font License 1.1 — see `assets/OFL.txt`.
