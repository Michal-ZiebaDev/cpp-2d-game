# C++ 2D Game (SFML)

Simple 2D game written in C++ using SFML. The goal of this project is to demonstrate a basic game loop, player movement and simple collision with window borders.

## Features

- 2D window with fixed resolution
- Player rectangle that moves using keyboard
- Simple collision with window edges
- Basic game loop structure in C++

## Controls

- **W / A / S / D** – move the player

## Example

The game opens a window (800x600) with a green square in the center.

- You can move the square using **WASD**
- The player cannot leave the window area (collision with borders)
- The window refreshes at 60 FPS

## Build instructions (CMake + SFML)

Requirements:
- C++17 compiler
- CMake
- SFML 2.5+ installed

### Basic build steps (Windows example)

1. Install SFML (e.g. SFML 2.5.1)
2. Clone this repository
3. In the project folder run:

```bash
cmake -B build
cmake --build build
```

The executable will be created in the `build` directory.

## Project structure

- `CMakeLists.txt` – CMake configuration
- `src/main.cpp` – game entry point and main loop

## Author

**Michał Zięba**  
GitHub: [Michal-ZiebaDev](https://github.com/Michal-ZiebaDev)
