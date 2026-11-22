#include "game.h"


// global variables with user defined datatypes
Player player;
int score; int highScore;
float timeLeft, fireTimer, spawnTimer;
Laser lasers[MAX_LASERS] ; // constant  array upto 10 defined in game.h
GameState state;
bool quitRequested;


void initGame(void) {
    
    initPlayer(&player); // initializes player
    initLasers(lasers); // initializes lasers
    initEnemies(); // initializes enimies

    player.health = MAX_HEALTH; // defined in game.h

    score = 0;
    highScore = loadHighScore(); // file function
    timeLeft = GAME_TIME; // defined in game.h

    fireTimer = 0;
    spawnTimer = 0;
    state = STATE_PLAYING; // defined in game.h
}



void handlePause(void) {
    
    // used to pause or resume game
    if (IsKeyPressed(KEY_ESCAPE)) {

        if (state == STATE_PLAYING) state = STATE_PAUSED;

        else if (state == STATE_PAUSED) state = STATE_PLAYING;
    }

    // restarts game when paused or game over
    if ((state == STATE_GAMEOVER || state == STATE_PAUSED) && IsKeyPressed(KEY_R)) initGame();
}


int main(void) {
    
    // initializing main window
    // parameters are defined in game.h
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders");


    SetExitKey(KEY_NULL); // see later

    SetTargetFPS(60); // FPS 

    initAudio(); // from game.h

    initGame(); // defined above

    quitRequested = false; // global parameter

    while (quitRequested == false) {

        if (IsKeyPressed(KEY_Q)) quitRequested = true;

        handlePause(); //declared above
        if (state == STATE_PLAYING) {
            
            // stores times in seconds of previous frame
            float dt = GetFrameTime(); // raylib function

            fireTimer -= dt; // controls when a player can fire     

            handlePlayerInput(&player); // declared in game.h

            if (IsKeyDown(KEY_SPACE)) fireLaser(lasers, &player, &fireTimer);
            

            updatePlayer(&player); // defined in game.h

            updateLasers(lasers); // defined in game.h

            updateEnemies(); //defined in game.h

            spawnTimer += dt; // keeps track of how much time has passed since last enemy
            float spawnInterval = 1.0;

            if (spawnTimer >= spawnInterval) {
                spawnTimer = 0;

                int result = GetRandomValue(0, 1); // function in Raylib

                if (result == 0) spawnAlien(); // declared in game.h
                else spawnAsteroid(); // declared in game.h

            }        

            // functions imported from game.h

            // checks if a laser hits  an asteriod or an asteriod hits the spaceship
            checkLaserEnemyCollisions(&score, lasers, asteroids, m_asteroids, 100);
            checkPlayerCollisions(&player.health, &player, asteroids, m_asteroids, &state);

            // checks if a laser hits an alien or an alien hits the spaceship
            checkLaserEnemyCollisions(&score, lasers, aliens, m_aliens, 150);
            checkPlayerCollisions(&player.health, &player, aliens, m_aliens, &state);

            updateTimer(&timeLeft, &state);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // imported from game.h
        drawPlayer(&player);  drawLasers(lasers); drawEnemies();
        drawHUD(score, timeLeft, player.health);


        // when game is paused
        if (state == STATE_PAUSED) DrawText("Game Paused", 300, 300, 30, YELLOW);

        // when game is over
        if (state == STATE_GAMEOVER) {
            if (score > highScore) {
                highScore = score;
                saveHighScore(highScore);
            }

            drawGameOver(score);

        }

        EndDrawing();

    }

    unloadAudio(); CloseWindow();

    return 0;
}


