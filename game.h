/* 
this is a header file containing shared declarations 
which will be used across multiple c files
*/

#ifndef GAME_H
#define GAME_H

// if GAME_H is not defined it will be defined by the second line
// used to prevent the same header file to be used multiple times in the same c file


#include "raylib.h"
#include <stdbool.h>


// all the constants are defined below 
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_LASERS 10
#define m_asteroids 8
#define m_aliens 8
#define MAX_HEALTH 100
#define GAME_TIME 120.0f


// player structure
typedef struct Player {
    Rectangle rect;
    float speed;
    int health;
} Player;


// laser structure
typedef struct Laser {
    Rectangle rect;
    float speed;
    bool active;
} Laser;


// enemy structure
typedef struct enemy {
    Rectangle pos;
    float speedY;
    bool active;
}enemy;


// userdefined datatype -- here each state is represented using its index
// PLAYING index is 0
typedef enum GameState {
    STATE_PLAYING,
    STATE_PAUSED,
    STATE_GAMEOVER
} GameState;


// extern means that the array exists somewhere else
// It can use this array but it does not create a copy over here
extern enemy asteroids[m_asteroids];
extern enemy aliens[m_aliens];


// function declaration 
void initPlayer(Player *p);
void handlePlayerInput(Player *p);
void updatePlayer(Player *p);
void drawPlayer(Player *p);
void initLasers(Laser lasers[]);
void fireLaser(Laser lasers[], Player *p, float *fireTimer);
void updateLasers(Laser lasers[]);
void drawLasers(Laser lasers[]);

// void as parameters means that no parameter will be taken -- just a declaration
void initEnemies(void);
void spawnAsteroid(void);
void spawnAlien(void);
void updateEnemies(void);
void drawEnemies(void);
void initAudio(void);
void playShootSound(void);
void playExplosionSound(void);
void unloadAudio(void);
void checkLaserEnemyCollisions(int *score, Laser lasers[], enemy enemies[], int count, int pointsPerKill);
void checkPlayerCollisions(int *health, Player *p, enemy enemies[], int count, GameState *state);
void updateTimer(float *timeLeft, GameState *state);
void drawHUD(int score, float timeLeft, int health);
void drawHealthBar(int health);
void drawGameOver(int score);

// file function declarations
int loadHighScore(void);
void saveHighScore(int score);


#endif

