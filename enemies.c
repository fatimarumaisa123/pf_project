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
