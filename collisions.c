#include "game.h"
#include <math.h>


#define ENEMY_DAMAGE 20


// checsks whether a laser hits an enemy 
void checkLaserEnemyCollisions(int *score, Laser lasers[], enemy enemies[], int count, int pointsPerKill) {

    for (int i = 0; i < MAX_LASERS; i++) {
        if (!lasers[i].active) continue;

        for (int j = 0; j < count; j++) {
            if (!enemies[j].active) continue;
            
            // deactivates laser and enemy after they collide 
            if (CheckCollisionRecs(lasers[i].rect, enemies[j].pos)) {
                lasers[i].active = false; 
                enemies[j].active = false; 
                
                *score += pointsPerKill; // adds points to the players score
                
                playExplosionSound(); // plays explosion sound

                break; 
            }
        }
    }
}


// checkcs enermy collision with spaceship
void checkPlayerCollisions(int *health, Player *p, enemy enemies[], int count, GameState *state) {

    for (int i = 0; i < count; i++) {
        if (!enemies[i].active) continue;

        // Check if enemy intersects with player 
        if (CheckCollisionRecs((*p).rect, enemies[i].pos)) {
            enemies[i].active = false;

            playExplosionSound();  // plays explosion sound
            (*health) -= ENEMY_DAMAGE;  // Reduce health by 20 -- defined above

            // ends game if health is 0
            if (*health <= 0) {
                *health = 0;
                *state = STATE_GAMEOVER;
            }
        }
    }
}


// decreases timer from 120 seconds to 0
void updateTimer(float *timeLeft, GameState *currentState) {

    if (*timeLeft > 0) { 
        *timeLeft -= GetFrameTime(); // gets time from previous frame

        // prevents timer from going negative
        if (*timeLeft <= 0) {
            *timeLeft = 0;
            *currentState = STATE_GAMEOVER;
        }
    }
}


// Draws the health bar on the screen based on current health points.
void drawHealthBar(int health) {

    // limits health between 0 and 100
    if (health < 0) health = 0;
    if (health > MAX_HEALTH) health = MAX_HEALTH;

    // produces a health bar on the screen
    int barWidth = 200;
    int barHeight = 20;
    int posX = SCREEN_WIDTH - 220;
    int posY = 20;

    // Background bar 
    DrawRectangle(posX, posY, barWidth, barHeight, DARKGRAY);
    
    // changes health bar color depending on health
    Color healthColor = GREEN;
    if (health < MAX_HEALTH / 2 ) healthColor = YELLOW;
    if (health < MAX_HEALTH / 4) healthColor = RED;

    float currentWidth = (float)barWidth * ((float)health / MAX_HEALTH);
    DrawRectangle(posX, posY, (int)currentWidth, barHeight, healthColor);
    
    // Border outline
    DrawRectangleLines(posX, posY, barWidth, barHeight, WHITE);
    DrawText("HEALTH", posX, posY - 18, 10, WHITE);
}



// Draws the complete Heads-Up Display (Score, Timer, and Health).
void drawHUD(int score, float timeLeft, int health) {



    // Format and Draw Countdown Timer in format of Minutes and seocnds
    int totalSeconds = (int)ceil(timeLeft); // ceil is <math.h> function used for rounding up
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    
    const char *timerText = TextFormat("TIME: %02d:%02d", minutes, seconds);
    DrawText(timerText, (SCREEN_WIDTH - MeasureText(timerText, 20)) / 2, 20, 20, WHITE);

    // draws timer on the screen
    DrawText(TextFormat("SCORE: %05d", score), 20, 20, 20, WHITE);

    // Draw Health Bar
    drawHealthBar(health);
}


// displays score when game is over along with score
void drawGameOver(int score) {
    // background
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, Fade(BLACK, 0.8f));

    // Game Over Text
    DrawText("GAME OVER", SCREEN_WIDTH / 2 - MeasureText("GAME OVER", 40) / 2, SCREEN_HEIGHT / 3, 40, RED);
    
    // Final Score Display
    DrawText(TextFormat("Final Score: %d", score), SCREEN_WIDTH / 2 - MeasureText(TextFormat("Final Score: %d", score), 20) / 2, SCREEN_HEIGHT / 3 + 60, 20, WHITE);

    // Instructions for restart/quit
    DrawText("Press [R] to Restart or [Q] to Quit", SCREEN_WIDTH / 2 - MeasureText("Press [R] to Restart or [Q] to Quit", 18) / 2, SCREEN_HEIGHT / 2 + 40, 18, LIGHTGRAY);
