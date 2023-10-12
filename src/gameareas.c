#include <stdio.h>
#include <stdint.h>
#include "gamemain.h"
#include "charactertest.h"
#include "gameareas.h"
#include "spriteoperations.h"

uint8_t area1x1[7][10] =    {   {   1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                                {   1, 1, 0, 1, 1, 1, 0, 1, 0, 0 },
                                {   1, 0, 0, 0, 1, 0, 5, 1, 0, 1 },
                                {   1, 1, 1, 0, 0, 0, 1, 1, 1, 1 },
                                {   1, 1, 1, 0, 1, 1, 1, 1, 8, 1 },
                                {   1, 1, 1, 0, 1, 1, 1, 1, 0, 1 }};

uint8_t area2x1[7][10] =    {   {   1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   1, 1, 0, 0, 5, 0, 1, 0, 0, 0 },
                                {   0, 0, 0, 1, 1, 0, 0, 0, 1, 1 },
                                {   1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
                                {   1, 1, 0, 0, 0, 0, 1, 1, 1, 1 },
                                {   1, 0, 2, 1, 1, 0, 5, 0, 1, 0 },
                                {   1, 1, 1, 1, 1, 1, 1, 0, 1, 1 }};

uint8_t area3x1[7][10] =    {   {   1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   0, 0, 0, 0, 0, 0, 0, 5, 0, 1 },
                                {   1, 1, 1, 1, 2, 1, 1, 1, 0, 1 },
                                {   1, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                                {   0, 1, 0, 1, 1, 1, 2, 1, 2, 1 },
                                {   1, 2, 0, 2, 1, 1, 1, 0, 2, 1 },
                                {   1, 1, 0, 2, 2, 2, 1, 1, 1, 1 }};

uint8_t area1x2[7][10] =    {   {   1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
                                {   1, 1, 1, 0, 1, 1, 1, 1, 0, 0 },
                                {   1, 1, 0, 0, 0, 1, 0, 1, 1, 0 },
                                {   1, 1, 0, 1, 0, 1, 0, 5, 1, 0 },
                                {   1, 1, 0, 1, 0, 0, 0, 1, 1, 0 },
                                {   1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
                                {   1, 0, 0, 0, 0, 1, 0, 0, 0, 0 }};

uint8_t area2x2[7][10] =    {   {   1, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
                                {   0, 1, 1, 1, 1, 1, 1, 6, 1, 1 },
                                {   0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
                                {   0, 0, 0, 0, 1, 1, 1, 0, 0, 1 },
                                {   1, 1, 1, 0, 1, 1, 0, 0, 5, 1 },
                                {   0, 0, 1, 0, 1, 0, 0, 0, 0, 0 }};

uint8_t area3x2[7][10] =    {   {   2, 2, 0, 2, 2, 2, 2, 2, 2, 2 },
                                {   2, 2, 0, 2, 2, 2, 2, 5, 2, 2 },
                                {   2, 2, 0, 2, 2, 2, 2, 0, 1, 2 },
                                {   0, 2, 0, 0, 0, 0, 0, 0, 2, 2 },
                                {   2, 1, 2, 2, 1, 0, 2, 2, 2, 2 },
                                {   2, 2, 2, 2, 2, 2, 11, 11, 0, 2 },
                                {   0, 2, 0, 2, 1, 2, 11, 11, 11, 2 }};

uint8_t area1x3[7][10] =    {   {   1, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
                                {   1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
                                {   1, 0, 5, 0, 0, 0, 5, 0, 0, 0 },
                                {   1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                                {   1, 0, 1, 0, 5, 0, 0, 1, 0, 1 },
                                {   1, 0, 0, 0, 0, 0, 0, 5, 0, 1 },
                                {   1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }};

uint8_t area2x3[7][10] =    {   {   0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
                                {   0, 1, 2, 0, 1, 1, 0, 1, 0, 0 },
                                {   0, 0, 0, 0, 0, 0, 0, 5, 2, 1 },
                                {   1, 0, 1, 2, 0, 1, 1, 0, 0, 1 },
                                {   1, 0, 0, 2, 0, 5, 0, 1, 0, 0 },
                                {   1, 2, 0, 1, 0, 2, 0, 0, 0, 0 },
                                {   1, 1, 1, 1, 1, 1, 1, 2, 1, 1 }};

uint8_t area3x3[7][10] =    {   {   0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                {   0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
                                {   1, 1, 1, 0, 1, 0, 0, 0, 1, 1 },
                                {   1, 1, 1, 0, 0, 0, 1, 5, 1, 1 },
                                {   0, 0, 0, 0, 1, 1, 1, 0, 1, 1 },
                                {   0, 1, 1, 1, 1, 1, 1, 0, 7, 1 },
                                {   1, 1, 1, 1, 1, 1, 1, 2, 1, 1 }};

uint8_t checkCollision(uint8_t *suggestedMove, Character *heroPosition)
{
    int8_t directionX = DO_NOT_MOVE;
    int8_t directionY = DO_NOT_MOVE;
    uint8_t returnMove = DO_NOT_MOVE;
    uint8_t getX = heroPosition->locationX;
    uint8_t getY = heroPosition->locationY;
    uint8_t areaCode = heroPosition->areaCode;

    if(*suggestedMove == MOVE_UP) directionY--;
    else if(*suggestedMove == MOVE_DOWN) directionY++;
    else if(*suggestedMove == MOVE_RIGHT) directionX++;
    else if(*suggestedMove == MOVE_LEFT) directionX--;

    uint8_t obstacle = getArea(areaCode, getY + directionY, getX + directionX);
    uint8_t currentIsGrave = getArea(areaCode, getY, getX);
    if(currentIsGrave != 11)
    {
        currentIsGrave = 0;
    }

    if(obstacle != 0 && obstacle != 6 && obstacle != 7 && obstacle != 8 && obstacle != 11) returnMove = DO_NOT_MOVE; // Check for shield, sword, heart, grave
    else returnMove = *(suggestedMove) + currentIsGrave;

    if(heroPosition->locationY == 0 && *suggestedMove == MOVE_UP) returnMove = MOVE_SCREEN_UP;
    else if(heroPosition->locationY == (GAME_MAX_Y - 1) && *suggestedMove == MOVE_DOWN) returnMove = MOVE_SCREEN_DOWN;
    else if(heroPosition->locationX == (GAME_MAX_X - 1) && *suggestedMove == MOVE_RIGHT) returnMove = MOVE_SCREEN_RIGHT;
    else if(heroPosition->locationX == 0 && *suggestedMove == MOVE_LEFT) returnMove = MOVE_SCREEN_LEFT;

    if(obstacle == 6)
    {
        area2x2[1][5] = 0;
        if(heroPosition->characterModel == 0)
        {
            heroPosition->characterModel = 1;
        }
        else if(heroPosition->characterModel == 2)
        {
            heroPosition->characterModel = 3;
        }
        changeArea(areaCode, getY + directionY, getX + directionX, obstacle);
    }

    else if(obstacle == 7)
    {
        area3x3[6][6] = 0;
        if(heroPosition->characterModel == 0)
        {
            heroPosition->characterModel = 2;
        }
        else if(heroPosition->characterModel == 1)
        {
            heroPosition->characterModel = 3;
        }
        changeArea(areaCode, getY + directionY, getX + directionX, obstacle);
    }

    else if(obstacle == 8)
    {
        changeArea(areaCode, getY + directionY, getX + directionX, obstacle);
        heroPosition->health++;
        drawHealth(heroPosition->health);
    }

    else if(obstacle == 5)
    {
        if(heroPosition->characterModel == 0 || heroPosition->characterModel == 2)
        {
            heroPosition->health -= 2;
        }
        else if(heroPosition->characterModel == 1)
        {
            heroPosition->health -= 1;
        }
        changeArea(areaCode, getY + directionY, getX + directionX, obstacle);
        heroPosition->slayedMonsters += 1;
        drawHealth(heroPosition->health);
    }

    return returnMove;
}

uint8_t getArea(uint8_t areaCode, uint8_t getY, uint8_t getX)
{
    uint8_t areaItem;
    pointerToArray *areas;

    if(areaCode == 0) areas = &area1x1;
    else if(areaCode == 1) areas = &area2x1;
    else if(areaCode == 2) areas = &area3x1;
    else if(areaCode == 3) areas = &area1x2;
    else if(areaCode == 4) areas = &area2x2;
    else if(areaCode == 5) areas = &area3x2;
    else if(areaCode == 6) areas = &area1x3;
    else if(areaCode == 7) areas = &area2x3;
    else if(areaCode == 8) areas = &area3x3;
    else areas = 0;

    areaItem = (*areas)[getY][getX];
    return areaItem;
}

void changeArea(uint8_t areaCode, uint8_t getY, uint8_t getX, uint8_t category)
{
    if(category == CAT_MONSTER)
    {
        if(areaCode == 0)
        {
            area1x1[getY][getX] = 11;
        }
        else if(areaCode == 1)
        {
            area2x1[getY][getX] = 11;
        }
        else if(areaCode == 2)
        {
            area3x1[getY][getX] = 11;
        }
        else if(areaCode == 3)
        {
            area1x2[getY][getX] = 11;
        }
        else if(areaCode == 4)
        {
            area2x2[getY][getX] = 11;
        }
        else if(areaCode == 5)
        {
            area3x2[getY][getX] = 11;
        }
        else if(areaCode == 6)
        {
            area1x3[getY][getX] = 11;
        }
        else if(areaCode == 7)
        {
            area2x3[getY][getX] = 11;
        }
        else if(areaCode == 8)
        {
            area3x3[getY][getX] = 11;
        }
    }
    else if(category == 6)
    {
        area2x2[getY][getX] = 0;
    }
    else if(category == 7)
    {
        area3x3[getY][getX] = 0;
    }
    else if(category == 8)
    {
        area1x1[getY][getX] = 0;
    }

    drawFullSprite(getX, getY, CAT_MONSTER, 2);
}
