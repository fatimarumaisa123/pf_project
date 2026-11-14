#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>

// --- SHARED CONSTANTS & STRUCTURES (Agreed with team) ---
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_LASERS 10
#define MAX_ENEMIES 20
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

/**
 * Checks collisions between active enemies and the player.
 * Reduces player health if hit, deactivates the enemy, and transitions to Game Over if health reaches 0.
 */
void checkPlayerCollisions(int *health, Player *player, Enemy enemies[], GameState *currentState) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!enemies[i].active) continue;

        // Check if enemy rectangle intersects with player rectangle
        if (CheckCollisionRecs(player->rect, enemies[i].rect)) {
            enemies[i].active = false; // Deactivate enemy on impact
            (*health) -= 20;           // Reduce health by 20 (adjust damage as needed)

            if (*health <= 0) {
                *health = 0;
                *currentState = STATE_GAMEOVER;
            }
        }
    }
}

/**
 * Updates the 2-minute (120 seconds) countdown timer.
 * Ends the game when timeLeft reaches zero.
 */
void updateTimer(float *timeLeft, GameState *currentState) {
    if (*timeLeft > 0) {
        *timeLeft -= GetFrameTime(); // Subtract time elapsed since last frame
        if (*timeLeft <= 0) {
            *timeLeft = 0;
            *currentState = STATE_GAMEOVER;
        }
    }
}

/**
 * Draws the health bar on the screen based on current health points.
 */
void drawHealthBar(int health) {
    int barWidth = 200;
    int barHeight = 20;
    int posX = SCREEN_WIDTH - 220;
    int posY = 20;

    // Background bar (empty container)
    DrawRectangle(posX, posY, barWidth, barHeight, DARKGRAY);
    
    // Health fill bar (color changes based on health level)
    Color healthColor = GREEN;
    if (health < 50) healthColor = YELLOW;
    if (health < 25) healthColor = RED;

    float currentWidth = (float)barWidth * ((float)health / 100.0f);
    DrawRectangle(posX, posY, (int)currentWidth, barHeight, healthColor);
    
    // Border outline
    DrawRectangleLines(posX, posY, barWidth, barHeight, WHITE);
    DrawText("HEALTH", posX, posY - 18, 10, WHITE);
}

/**
 * Draws the complete Heads-Up Display (Score, Timer, and Health).
 */
void drawHUD(int score, float timeLeft, int health) {
    // Draw Score
    DrawText(TextFormat("SCORE: %05d", score), 20, 20, 20, WHITE);

    // Format and Draw Countdown Timer (Minutes:Seconds)
    int minutes = (int)(timeLeft) / 60;
    int seconds = (int)(timeLeft) % 60;
    DrawText(TextFormat("TIME: %02d:%02d", minutes, seconds), SCREEN_WIDTH / 2 - 50, 20, 20, WHITE);

    // Draw Health Bar
    drawHealthBar(health);
}

/**
 * Draws the Game Over screen with final score and restart/quit options.
 */
void drawGameOver(int score) {
    // Semi-transparent dark overlay
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, Fade(BLACK, 0.8f));

    // Game Over Text
    DrawText("GAME OVER", SCREEN_WIDTH / 2 - MeasureText("GAME OVER", 40) / 2, SCREEN_HEIGHT / 3, 40, RED);
    
    // Final Score Display
    DrawText(TextFormat("Final Score: %d", score), SCREEN_WIDTH / 2 - MeasureText(TextFormat("Final Score: %d", score), 20) / 2, SCREEN_HEIGHT / 3 + 60, 20, WHITE);

    // Instructions for restart/quit
    DrawText("Press [R] to Restart or [Q] to Quit", SCREEN_WIDTH / 2 - MeasureText("Press [R] to Restart or [Q] to Quit", 18) / 2, SCREEN_HEIGHT / 2 + 40, 18, LIGHTGRAY);
}
