# Space Invaders

## 1. Project Overview 
Space Invaders is a real-time 2D arcade shooter built from scratch in C using the Raylib graphics library.

Developed by:
* Afnan Ahmed 26K-0002
* Rumaisa Fatima 26K-0018
* Uzair Nauman 26K-0016


The player pilots a spaceship along the lower part of the screen, moving with W/A/S/D or arrow keys and firing lasers with the spacebar. They shoot asteroids and alien invaders while keeping the health bar above zero and scoring as many points as possible within a 2-minute countdown.

## 2. Features
* Player movement: The ship moves in four directions with W/A/S/D or the arrow keys. It is kept inside the screen bounds, in the lower part of the viewport.

* Shooting bullets: The spacebar fires lasers. Lasers sit in an array with an active flag, move each frame, and deactivate off-screen. A fire-rate limit stops spamming. The spec also describes a multi-laser spread mode.

* Enemy movement: Asteroids and aliens spawn at random positions, speeds, and directions. They move every frame and deactivate when they leave the screen. The spec adds kamikaze attackers that dive toward the ship.

* Collision detection: Rectangles are compared with CheckCollisionRecs using nested loops. Lasers are checked against enemies, and enemies against the player.

* Scoring system: Points are added for each destroyed enemy, shown live on the HUD. The high score is saved to and loaded from a file.

* Health system: The player has a health bar (0-100%) that drops when hit. The game ends when it reaches zero.

## 3.  Technologies Used

* C Programming Language
* Raylib 
* GCC Compiler
* Git & Github

## 4. Installation & Setup

### 1. Prerequisites
- GCC Compiler
- Raylib Library
- Git


### 2. Install Dependencies (Windows)

1. Install [MSYS2](https://www.msys2.org/).
2. Open the UCRT64 terminal and install **GCC Compiler** and **Raylib**:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-raylib
```

3. Verify GCC installation:

```bash
gcc --version
```

### 3. Cloning the Repository
Clone the Repository by using the following the command 
```bash
git https://github.com/fatimarumaisa123/pf_project/tree/main
```

### 4. Compiling the Project
The code can be combined once GCC has been installed. The code can be compiled using the following command

```bash
gcc *.c -o SpaceInvaders -lraylib -lopengl32 -lgdi32 -lwinmm
```

### 5. Executing the Game
After the code has beeen compiled, it can be executed using the following command

```bash
./SpaceInvaders.exe
```

