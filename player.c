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



// funciton used to prevent spaceship from moving outside the screen 
void updatePlayer(Player *p) {

    // restrictions on left and right
    if ((*p).rect.x < 0) (*p).rect.x = 0;

    if ((*p).rect.x > GetScreenWidth() - (*p).rect.width)  
        (*p).rect.x = GetScreenWidth() - (*p).rect.width;

    // restrictions on up and down
    
    // prevents the space ship from moving down the screen
    if ((*p).rect.y > GetScreenHeight() - (*p).rect.height) 
        (*p).rect.y = GetScreenHeight() - (*p).rect.height;

    // this prevents the spaceship from moving 70% above the screen
    if ((*p).rect.y < GetScreenHeight() * 0.7f) (*p).rect.y = GetScreenHeight() * 0.7f;


}


// displays the spaceship on the screen
void drawPlayer(Player *p) {
    
    // change the color -- replace BLUE with RED
    DrawRectangleRec((*p).rect, BLUE);
}