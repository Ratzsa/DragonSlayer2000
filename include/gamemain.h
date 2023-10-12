#ifndef __GAME_MAIN_H
#define __GAME_MAIN_H

#include <stdint.h>

#define CAT_FILLSQUARE 0
#define CAT_TREES 1
#define CAT_HOUSES 2
#define CAT_TOOLS 3
#define CAT_HERO 4
#define CAT_MONSTER 5

#define DO_NOT_MOVE 0
#define MOVE_UP 1
#define MOVE_DOWN 2
#define MOVE_RIGHT 3
#define MOVE_LEFT 4

#define MOVE_SCREEN_UP 5
#define MOVE_SCREEN_DOWN 6
#define MOVE_SCREEN_RIGHT 7
#define MOVE_SCREEN_LEFT 8

#define GAME_MAX_X 10
#define GAME_MAX_Y 7

void gameMain(uint8_t *receivedControls);
void titleScreen();

#endif