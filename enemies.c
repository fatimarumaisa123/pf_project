#include<stdio.h>
#include<stdbool.h>
#include<raylib.h>
typedef struct {
    Rectangle rect; //holds enemies position
    float speedX;// horizontal movement of enemy (-ve left +ve right)
    float speedY;//vertical movement of enemy (-ve down +ve up)
    bool active;//true when enemy is on the screen false when enemy is destroyed or 
                //left the screen
} Enemy;
#define MAX_ASTEROIDS 8
#define MAX_ALIENS 8

Enemy asteroids[MAX_ASTEROIDS];
Enemy aliens[MAX_ALIENS];

void init_enemies() //at every start of the game setting active status false
                       // so that they donot exit basically initializing their status
 {
    for (int i=0;i<MAX_ASTEROIDS;i++)
    {
        asteroids[i].active = false;
    }
     for (int i=0;i<MAX_ALIENS;i++)
    {
        aliens[i].active = false;
    }

}


void spawnAsteroid() // spawning the aesteroids that are not active at random places
{
    for (int i=0;i<MAX_ASTEROIDS;i++)
    {
        if (asteroids[i].active==false)
        {
            asteroids[i].rect.x = GetRandomValue(0, 760);//setting up the random value
            asteroids[i].rect.y = -40;
            asteroids[i].rect.width = 40;
            asteroids[i].rect.height = 40;
            asteroids[i].speedX = GetRandomValue(-2, 2);
            asteroids[i].speedY = GetRandomValue(2, 5);
            asteroids[i].active = true;
            break;
        }
    }
}
void spawnAlien() // spawning the aliens that are not active at random places
{
    for (int i=0;i<MAX_ALIENS;i++)
    {
        if (aliens[i].active==false)
        {
            aliens[i].rect.x = GetRandomValue(0, 750);//setting up the random value
            aliens[i].rect.y = -40;
            aliens[i].rect.width = 50;
            aliens[i].rect.height = 40;
            aliens[i].speedX = GetRandomValue(-3, 3);
            aliens[i].speedY = GetRandomValue(1, 3);
            aliens[i].active = true;
            break;
        }
    }
}



