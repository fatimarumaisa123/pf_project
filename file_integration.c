#include "game.h"
#include <stdio.h>


int loadHighScore(void)//reads the saved score 
{
    int highscore = 0;//if no file exists yet
    // when the game runs for the very first time the high score is 0.

    FILE *file = fopen("highscore.txt", "r"); //opening in read mode 

    if (file != NULL) { //when the file opens
        fscanf(file, "%d", &highscore);//reads from file and storing in high score
        fclose(file);//closing the opened file
    }

    return highscore;
}

void saveHighScore(int score) {
    FILE *file = fopen("highscore.txt", "w");//opening in write mode

    if (file != NULL ) {
        fprintf(file, "%d", score); //writing the high score in the file
        fclose(file);
    }

    
}