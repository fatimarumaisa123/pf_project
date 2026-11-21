#include "game.h"


// global variables with user defined datatypes
Player player;
int score;
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

        if (state == STATE_PLAYING) {
            handlePause(); //declared above
            
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

        }

    }
}