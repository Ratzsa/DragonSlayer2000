#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "spriteoperations.h"
#include "controller.h"
#include "charactertest.h"
#include "gamemain.h"

void drawCharacter(Character *hero)
{
    drawFullSprite(hero->locationX, hero->locationY, CAT_HERO, hero->characterModel);
}

uint8_t setMovement(Controller *inGameControls, Character *heroLocation)
{
    uint8_t moveToSet = DO_NOT_MOVE;

    if(inGameControls->up) moveToSet = MOVE_UP;
    else if(inGameControls->down) moveToSet = MOVE_DOWN;
    else if(inGameControls->right) moveToSet = MOVE_RIGHT;
    else if(inGameControls->left) moveToSet = MOVE_LEFT;

    return moveToSet;
}

void moveCharacter(Character *heroMove, uint8_t *movement)
{
    switch(*movement)
    {
        case DO_NOT_MOVE:
            break;

        case MOVE_UP:
            heroMove->locationY--;
            break;

        case MOVE_DOWN:
            heroMove->locationY++;
            break;

        case MOVE_RIGHT:
            heroMove->locationX++;
            break;

        case MOVE_LEFT:
            heroMove->locationX--;
            break;

        case MOVE_SCREEN_UP:
            heroMove->areaCode -= 3;
            heroMove->locationY = 6;
            break;

        case MOVE_SCREEN_DOWN:
            heroMove->areaCode += 3;
            heroMove->locationY = 0;
            break;

        case MOVE_SCREEN_RIGHT:
            heroMove->areaCode += 1;
            heroMove->locationX = 0;
            break;

        case MOVE_SCREEN_LEFT:
            heroMove->areaCode -= 1;
            heroMove->locationX = 9;
            break;

        default:
            break;
    }
}