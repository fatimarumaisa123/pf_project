#include "game.h"

#define LASER_WIDTH 6
#define LASER_HEIGHT 15
#define LASER_SPEED 600
#define FIRE_DELAY 0.25f

void initLasers(Laser lasers[]) {
    for (int i = 0; i < MAX_LASERS; i++) {
        lasers[i].rect.width = LASER_WIDTH;
        lasers[i].rect.height = LASER_HEIGHT;
        lasers[i].rect.x = 0;
        lasers[i].rect.y = 0;
        lasers[i].speed = LASER_SPEED;
        lasers[i].active = false;
    }
}

// fires one laser from the top centre of the player when the fire timer has run out
void fireLaser(Laser lasers[], Player *p, float *fireTimer) {
    if (*fireTimer > 0) return;

    for (int i = 0; i < MAX_LASERS; i++) {
        if (!lasers[i].active) {
            lasers[i].rect.x = (*p).rect.x + ((*p).rect.width - lasers[i].rect.width) / 2;
            lasers[i].rect.y = (*p).rect.y - lasers[i].rect.height;
            lasers[i].active = true;
            *fireTimer = FIRE_DELAY;
            playShootSound();
            break;
        }
    }
}

// moves active lasers up and deactivates them once they leave the screen
void updateLasers(Laser lasers[]) {
    float dt = GetFrameTime();

    for (int i = 0; i < MAX_LASERS; i++) {
        if (!lasers[i].active) continue;

        lasers[i].rect.y -= lasers[i].speed * dt;

        if (lasers[i].rect.y + lasers[i].rect.height < 0) lasers[i].active = false;
    }
}

void drawLasers(Laser lasers[]) {
    for (int i = 0; i < MAX_LASERS; i++) {
        if (lasers[i].active) DrawRectangleRec(lasers[i].rect, GREEN);
    }
}