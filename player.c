#include <stdio.h>
#include "raylib.h"
#include "game.h"

// function used to initialize the Player
void initPlayer(Player *p) {


    // used to set screen width and height using another file game.h
    (*p).rect.width = 50; (*p).rect.height = 40; 

    // used to align the spaceship exactly in the center
    (*p).rect.x = (GetScreenWidth() - (*p).rect.width) / 2;
    (*p).rect.y = GetScreenHeight() - (*p).rect.height - 20;
    
    // used to initialized speed
    (*p).speed = 300; 
}


// function used to handle player input
void handlePlayerInput(Player *p) {


    // dt (Delta Time) stores the previous frame time -- used to change speed
    float dt = GetFrameTime();

    /*
     following keys are used to change the direction by simply mutliplying speed 
     with previous frames

     In raylib y axis is flipped hence moving up is reduction whereas moving down rise 
     (0,0) left corner of the screen
     */

    if (IsKeyDown(KEY_W)|| IsKeyDown(KEY_UP)) (*p).rect.y -= (*p).speed * dt;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) (*p).rect.y += (*p).speed * dt; 
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) (*p).rect.x -= (*p).speed * dt; 
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) (*p).rect.x += (*p).speed * dt;

}