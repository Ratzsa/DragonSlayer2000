#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "main.h"
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"
#include "sprites.h"
#include "gameareas.h"
#include "gamemain.h"
#include "charactertest.h"

uint8_t getRandomSprite(uint8_t category);

void drawSpriteLine(uint8_t startX, uint8_t startY, uint16_t row)
{
    for(uint8_t i = 0; i < 9; i++)
    {
        ssd1306_DrawPixel(startX, startY, (row >> (8 - i) & 1));
        startX++;
    }
}

void drawFullSprite(uint8_t startX, uint8_t startY, uint8_t category, uint8_t sprite)
{
    startX = (startX * 9) + 2;
    startY = startY * 9;
    for(uint8_t i = 0; i < 9; i++)
    {
        uint8_t row = getSpriteLine(category, sprite, i);
        drawSpriteLine(startX, startY, row);
        startY++;
    }
}

void drawLandscape(uint8_t areaCode)
{
    uint8_t playField[7][10];
    for(uint8_t i = 0; i < GAME_MAX_Y; i++)
    {
        for(uint8_t j = 0; j < GAME_MAX_X; j++)
        {
            playField[i][j] = getArea(areaCode, i, j);
        }
    }

    for(uint8_t i = 0; i < GAME_MAX_Y; i++)
    {
        for(uint8_t j = 0; j < GAME_MAX_X; j++)
        {
            uint8_t spriteNum;
            if(playField[i][j] < 3 || playField[i][j] == 5) // Tree or house, or monster
            {
                spriteNum = rand() % getRandomSprite(playField[i][j]);
            }
            else if(playField[i][j] == 6) // Shield
            {
                spriteNum = 0;
            }
            else if(playField[i][j] == 7) // Sword
            {
                spriteNum = 1;
            }
            else if(playField[i][j] == 8) // Heart
            {
                spriteNum = 2;
            }
            else if(playField[i][j] == 11) // Grave
            {
                spriteNum = 2;
            }
            else
            {
                spriteNum = 0;
            }

            drawFullSprite(j, i, playField[i][j], spriteNum);
        }
    }

    ssd1306_DrawRectangle(93, 0, 94, 63, White);
}

uint8_t getRandomSprite(uint8_t category)
{
    uint8_t numReturn;
    switch(category)
    {
        case 0:
            numReturn = 1;
            break;

        case 1:
            numReturn = 2;
            break;

        case 2:
            numReturn = 3;
            break;

        case 3:
            numReturn = 3;
            break;

        case 4:
            numReturn = 4;
            break;

        case 5:
            numReturn = 2;
            break;

        default:
            exit(8);
            break;
    }

    return numReturn;
}

void drawHealth(uint8_t health)
{
    uint8_t startX = 11;
    uint8_t startY = 1;
    for(uint8_t i = 0; i < 6; i++)
    {
        if(health > i)
        {
            drawFullSprite(startX, startY, 3, 2);
        }
        else
        {
            drawFullSprite(startX, startY, 0, 0);
        }
        startY++;
    }
}