#include "game.h"
#include<time.h>

enemy asteroids[m_asteroids]; //an array of struct
enemy aliens[m_aliens];
Sound laser;
Sound hit;

void initEnemies(void) //at every start of the game setting active status false
                       // so that they donot exit basically initializing their status
 {
    SetRandomSeed((unsigned int)time(NULL)); //different random values for every game to avoid predictability
    for (int i=0;i<m_asteroids;i++)
    {
        asteroids[i].active = false;
    }
     for (int i=0;i<m_aliens;i++)
    {
        aliens[i].active = false;
    }

}


void spawnAsteroid(void) // spawning the aesteroids that are not active at random places
{
    for (int i=0;i<m_asteroids;i++)
    {
        if (asteroids[i].active==false)
        {
            asteroids[i].pos.x = GetRandomValue(0, 760);//Random Aesteroid staring point from 
            //  across the top.
            // The maximum is 760 because the screen is 800 wide and the asteroid is
            // 40 wide (800 − 40). A larger x would start it partly off the right side
            asteroids[i].pos.y = -40;//aesteroids starts falling from hidden top
            asteroids[i].pos.width = 40;//sets the width of rectangle 
            asteroids[i].pos.height = 40;//sets the height of rectangle
            //asteroids[i].speedX = GetRandomValue(-2, 2);//moves theh aesteroid sideways
            asteroids[i].speedY = GetRandomValue(2, 5);//downward falling motion
            asteroids[i].active = true;//once it is spawned it becomes active
            break;
        }
    }
}
void spawnAlien(void) // spawning the aliens that are not active at random places
{
    for (int i=0;i<m_aliens;i++)
    {
        if (aliens[i].active==false)
        {
            aliens[i].pos.x = GetRandomValue(0, 750);//Random alien strating point from accross the top
            aliens[i].pos.y =-40;//aliens start falling from hidden top                  
            aliens[i].pos.width = 50;//the width of alien rectangle
            aliens[i].pos.height = 40;// the height of alien rectangle
            //aliens[i].speedX = GetRandomValue(-3, 3);//sideways movemnets
            aliens[i].speedY = GetRandomValue(1, 3);//downwards motion
            aliens[i].active = true;//once it is spawned it becomes active
            break;
        }
    }
}
void updateEnemies(void){
    for(int i=0;i<m_asteroids;i++){
        if(asteroids[i].active==true)
        {
           //asteroids[i].pos.x+=asteroids[i].speedX;//if speed x is 0 so it falls straight down
           // and if it has speed x so it will move the aesteroid side ways 
           asteroids[i].pos.y+=asteroids[i].speedY;//downward falling
           if(asteroids[i].pos.y > SCREEN_HEIGHT || //assuming the window is 600 tall y is the top edge of 
            //aesteroid if it is below 600 it is completely below the bottom of the screen
            asteroids[i].pos.x + asteroids[i].pos.width<0 || //x is the left edge so adding
            //width to for the right edge and less than 0 says that it has completely left 
            //the screen 
            asteroids[i].pos.x>SCREEN_WIDTH // assuming window is 800 wide, x is the left edge and if
            //it is past 800 that means the asteroid is outside the screen 
        ){
            asteroids[i].active = false;
        }

        }
    }
    for(int i=0;i<m_aliens;i++){
        if(aliens[i].active==true)
        {
           // aliens[i].pos.x+=aliens[i].speedX;
            aliens[i].pos.y+=aliens[i].speedY;
            if(aliens[i].pos.y>SCREEN_HEIGHT || aliens[i].pos.x>SCREEN_WIDTH || aliens[i].pos.x +
                 aliens[i].pos.width<0){
                aliens[i].active=false;
            }
        }
    }

}

void drawEnemies(void)//simple recatngle shaped enemies
{
    for (int i=0;i<m_asteroids;i++)
    {
        if(asteroids[i].active)
        DrawRectangleRec(asteroids[i].pos,YELLOW);
    }
    for(int i=0;i<m_aliens;i++)
    {
        if(aliens[i].active)
        DrawRectangleRec(aliens[i].pos,RED);
    }
    
}
void initAudio(void)
{
    InitAudioDevice();// start the audio system first
    laser = LoadSound("audio/laser.wav");
    hit = LoadSound("audio/hit.wav");
}
void playShootSound(void)
{
    PlaySound(laser);
}

void playExplosionSound(void)
{
    PlaySound(hit);
}
void unloadAudio(void)
{
    UnloadSound(laser);
    UnloadSound(hit);
    CloseAudioDevice();
}
