// Test main loop for the enemy module.
// Assumes your enemy code is saved as enemies.c in the same folder
// (change the #include below if your file has a different name).
#include "enemies.c"

#define SCREEN_W 800
#define SCREEN_H 600

float asteroidTimer = 0;
float alienTimer = 0;
            
void updateSpawns()
{
    asteroidTimer += GetFrameTime();
    alienTimer += GetFrameTime();

    if (asteroidTimer >= 1.0f)   // one asteroid per second
    {
        spawnAsteroid();
        asteroidTimer = 0;
    }
    if (alienTimer >= 2.0f)      // one alien every two seconds
    {
        spawnAlien();
        alienTimer = 0;
    }
}

int main(void)
{
    InitWindow(SCREEN_W, SCREEN_H, "Space Invaders - enemy test");
    SetTargetFPS(60);
    initEnemies();

    while (!WindowShouldClose())
    {
        // update
        updateSpawns();
        updateEnemies();

        // draw
        BeginDrawing();
        ClearBackground(BLACK);
        drawEnemies();
        DrawText("Enemy test", 10, 10, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}