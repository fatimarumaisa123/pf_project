#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>

// --- SHARED CONSTANTS & STRUCTURES (Agreed with team) ---
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_LASERS 10
#define MAX_ENEMIES 20
// Player Structure (Afnan's module)
typedef struct {
    Rectangle rect;
    Vector2 position;
    float speed;
    int health;
} Player;

// Laser Structure (Afnan's module)
typedef struct {
    Rectangle rect;
    Vector2 position;
    float speed;
    bool active;
} Laser;

// Enemy Structure (Rumaisa's module)
typedef struct {
    Rectangle rect;
    Vector2 position;
    Vector2 speed;
    int type; // 0 for Asteroid, 1 for Alien
    bool active;
} Enemy;

// Game States
typedef enum { STATE_PLAYING, STATE_PAUSED, STATE_GAMEOVER } GameState;


// --- UZAIR'S FUNCTIONS: IMPLEMENTATION ---
/**
 * Checks collisions between active lasers and active enemies using nested loops.
 * If a collision occurs, both the laser and enemy are deactivated, and points are added to the score pointer.
 */
void checkLaserEnemyCollisions(int *score, Laser lasers[], Enemy enemies[]) {
    for (int i = 0; i < MAX_LASERS; i++) {
        if (!lasers[i].active) continue;

        for (int j = 0; j < MAX_ENEMIES; j++) {
            if (!enemies[j].active) continue;

            // Check collision using raylib's built-in rectangle collision function
            if (CheckCollisionRecs(lasers[i].rect, enemies[j].rect)) {
                lasers[i].active = false; // Deactivate laser
                enemies[j].active = false; // Destroy enemy
                
                // Increase score based on enemy type (e.g., 100 for asteroids, 200 for aliens)
                if (enemies[j].type == 0) {
                    *score += 100;
                } else {
                    *score += 200;
                }
                break; // Exit inner loop once laser hits an enemy
            }
        }
    }
}



