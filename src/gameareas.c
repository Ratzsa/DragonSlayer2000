#include <stdio.h>
#include <stdint.h>
#include "gamemain.h"
#include "charactertest.h"
#include "gameareas.h"

uint8_t area1x1[7][10] =    {   {   1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                {   1, 1, 0, 1, 1, 1, 0, 1, 0, 0 },
                                {   1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
                                {   1, 1, 1, 0, 0, 0, 1, 1, 1, 1 },
                                {   1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
                                {   1, 1, 1, 0, 1, 1, 1, 1, 0, 1 }};

uint8_t area2x1[7][10] =    {   {   1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   1, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
                                {   0, 0, 0, 1, 1, 0, 0, 0, 1, 1 },
                                {   1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
                                {   1, 1, 0, 0, 0, 0, 1, 1, 1, 1 },
                                {   1, 1, 1, 1, 1, 0, 0, 0, 1, 0 },
                                {   1, 1, 1, 1, 1, 1, 1, 0, 1, 1 }};

uint8_t area3x1[7][10] =    {   {   1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                {   1, 1, 1, 1, 2, 1, 1, 1, 0, 1 },
                                {   1, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                                {   0, 1, 0, 1, 1, 1, 2, 1, 2, 1 },
                                {   1, 2, 0, 2, 1, 1, 1, 0, 2, 1 },
                                {   1, 1, 0, 2, 2, 2, 1, 1, 1, 1 }};

uint8_t area1x2[7][10] =    {   {   1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
                                {   1, 1, 1, 0, 1, 1, 1, 1, 0, 0 },
                                {   1, 1, 0, 0, 0, 1, 0, 1, 1, 0 },
                                {   1, 1, 0, 1, 0, 1, 0, 0, 1, 0 },
                                {   1, 1, 0, 1, 0, 0, 0, 1, 1, 0 },
                                {   1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
                                {   1, 0, 0, 0, 0, 1, 0, 0, 0, 0 }};

uint8_t area2x2[7][10] =    {   {   1, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
                                {   0, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
                                {   0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
                                {   0, 0, 0, 0, 1, 1, 1, 0, 0, 1 },
                                {   1, 1, 1, 0, 1, 1, 0, 0, 0, 1 },
                                {   0, 0, 1, 0, 1, 0, 0, 0, 0, 0 }};

uint8_t area3x2[7][10] =    {   {   2, 2, 0, 2, 2, 2, 2, 2, 2, 2 },
                                {   2, 2, 0, 2, 2, 2, 2, 0, 2, 2 },
                                {   2, 2, 0, 2, 2, 2, 2, 0, 1, 2 },
                                {   0, 2, 0, 0, 0, 0, 0, 0, 2, 2 },
                                {   2, 1, 2, 2, 1, 0, 2, 2, 2, 2 },
                                {   2, 2, 2, 2, 2, 2, 2, 2, 0, 2 },
                                {   0, 2, 0, 2, 1, 2, 2, 2, 2, 2 }};

uint8_t area1x3[7][10] =    {   {   1, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
                                {   1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
                                {   1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                {   1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                {   1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },
                                {   1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                {   1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }};

uint8_t area2x3[7][10] =    {   {   0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
                                {   0, 1, 2, 0, 1, 1, 0, 1, 0, 0 },
                                {   0, 0, 0, 0, 0, 0, 0, 0, 2, 1 },
                                {   1, 0, 1, 2, 0, 1, 1, 0, 0, 1 },
                                {   1, 0, 0, 2, 0, 0, 0, 1, 0, 0 },
                                {   1, 2, 0, 1, 0, 2, 0, 0, 0, 0 },
                                {   1, 1, 1, 1, 1, 1, 1, 2, 1, 1 }};

uint8_t area3x3[7][10] =    {   {   0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
                                {   1, 1, 1, 0, 1, 0, 0, 0, 1, 1 },
                                {   1, 1, 1, 0, 0, 0, 1, 0, 1, 1 },
                                {   0, 0, 0, 0, 1, 1, 1, 0, 1, 1 },
                                {   0, 1, 1, 1, 1, 1, 1, 0, 0, 1 },
                                {   1, 1, 1, 1, 1, 1, 1, 2, 1, 1 }};

uint8_t checkCollision(uint8_t *suggestedMove, Character *heroPosition)
{
    // pointerArray *areas = { &area1x1, &area2x1, &area3x1, &area1x2, &area2x2, &area3x2, &area1x3, &area2x3, &area3x3 };
    /*
    pointerToArray *areas;

    if(heroPosition->areaCode == 0) areas = &area1x1;
    if(heroPosition->areaCode == 1) areas = &area2x1;
    if(heroPosition->areaCode == 2) areas = &area3x1;
    if(heroPosition->areaCode == 3) areas = &area1x2;
    if(heroPosition->areaCode == 4) areas = &area2x2;
    if(heroPosition->areaCode == 5) areas = &area3x2;
    if(heroPosition->areaCode == 6) areas = &area1x3;
    if(heroPosition->areaCode == 7) areas = &area2x3;
    if(heroPosition->areaCode == 8) areas = &area3x3;
    */

    int8_t directionX = DO_NOT_MOVE;
    int8_t directionY = DO_NOT_MOVE;
    uint8_t returnMove = DO_NOT_MOVE;
    uint8_t getX = heroPosition->locationX;
    uint8_t getY = heroPosition->locationY;
    uint8_t areaCode = heroPosition->areaCode;

    if(*suggestedMove == MOVE_UP) directionY--;
    if(*suggestedMove == MOVE_DOWN) directionY++;
    if(*suggestedMove == MOVE_RIGHT) directionX++;
    if(*suggestedMove == MOVE_LEFT) directionX--;

    uint8_t obstacle = getArea(areaCode, getY + directionY, getX + directionX);

    if(obstacle != 0) returnMove = DO_NOT_MOVE;
    else returnMove = *suggestedMove;

    if(heroPosition->locationY == 0 && *suggestedMove == MOVE_UP) returnMove = MOVE_SCREEN_UP;
    if(heroPosition->locationY == (GAME_MAX_Y - 1) && *suggestedMove == MOVE_DOWN) returnMove = MOVE_SCREEN_DOWN;
    if(heroPosition->locationX == (GAME_MAX_X - 1) && *suggestedMove == MOVE_RIGHT) returnMove = MOVE_SCREEN_RIGHT;
    if(heroPosition->locationX == 0 && *suggestedMove == MOVE_LEFT) returnMove = MOVE_SCREEN_LEFT;

    return returnMove;
}

uint8_t getArea(uint8_t areaCode, uint8_t getY, uint8_t getX)
{
    uint8_t areaItem;
    // pointerArray *areas = { &area1x1, &area2x1, &area3x1, &area1x2, &area2x2, &area3x2, &area1x3, &area2x3, &area3x3 };
    pointerToArray *areas;

    if(areaCode == 0) areas = &area1x1;
    if(areaCode == 1) areas = &area2x1;
    if(areaCode == 2) areas = &area3x1;
    if(areaCode == 3) areas = &area1x2;
    if(areaCode == 4) areas = &area2x2;
    if(areaCode == 5) areas = &area3x2;
    if(areaCode == 6) areas = &area1x3;
    if(areaCode == 7) areas = &area2x3;
    if(areaCode == 8) areas = &area3x3;

    areaItem = (*areas)[getY][getX];
    return areaItem;
}