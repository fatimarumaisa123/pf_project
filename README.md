# Space Invaders

## 1. Project Overview 

Space Invaders is a real-time 2D arcade shooter built from scratch in C using the Raylib graphics library.

Developed by:
* Afnan Ahmed 26K-0002
* Rumaisa Fatima 26K-0018
* Uzair Nauman 26K-0016



The player pilots a spaceship along the lower part of the screen, moving with W/A/S/D or arrow keys and firing lasers with the spacebar. They shoot asteroids and alien invaders while keeping the health bar above zero and scoring as many points as possible within a 2-minute countdown.

## 2. Features
![Screenshot](https://github.com/user-attachments/assets/4d3bff74-1963-4549-97c5-14bf0ef1bf3e)
* Player movement: The ship moves in four directions with W/A/S/D or the arrow keys. It is kept inside the screen bounds, in the middle part of the viewport.

* Shooting bullets: The spacebar fires lasers. Lasers sit in an array with an active flag, move each frame, and deactivate off-screen. A fire-rate limit stops spamming. 

* Enemy movement: Asteroids and aliens spawn at random positions, speeds, and directions. They move every frame and deactivate when they leave the screen. 

* Collision detection: Shapes are compared with CheckCollisionRecs using nested loops. Lasers are checked against enemies, and enemies against the player.

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
git clone https://github.com/fatimarumaisa123/pf_project/tree/main
cd pf_project
```

### 4. Compiling the Project
The code can be combined once GCC has been installed. The code can be compiled using the following command

```bash
gcc *.c -o SpaceInvaders -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

### 5. Executing the Game
After the code has beeen compiled, it can be executed using the following command

```bash
./SpaceInvaders.exe
```

## 5. Project Strucutre 
![Screenshot](https://github.com/user-attachments/assets/e40978d3-e8f8-4086-9c56-2905b044cbee)


```text
Space-Invaders/
│
├── game.h
├── main.c
├── players.c
├── enemies.c
├── lasers.c
├── collisions.c
├── file_integration.c
│
├── highscore.txt
│
├── audio/
│   ├── hit.wav
│   └── laser.wav
│
└── README.md
```

## 6. How to Play

![Screenshot](https://github.com/user-attachments/assets/59809553-7d80-4ef2-b68d-86da45000714)


- **W / Up Arrow:** Move up.
- **A / Left Arrow:** Move left.
- **S / Down Arrow:** Move down.
- **D / Right Arrow:** Move right.
- **Spacebar:** Shoot.
- **Q** Quit The game
- **R** Restart the Game
- **Esc:** Pause the game

Avoid enemy attacks and destroy aliens and asteriods to earn points.

## 7. Member Contributions


| Team Member | Contributions |
|---|---|
| Afnan Ahmed| README.md, game.h, main.c, player.c |
| Rumaisa Fatima | file_integration.c, eninimies.c |
| Uzair Nauman | collisions.c, lasers.c |


## 8. Acknowledgements


- [Raylib](https://www.raylib.com/) for providing the graphics and game development library.
- [GCC](https://gcc.gnu.org/) for compiling the C code.
- [GitHub](https://github.com/) for version control and team collaboration.
