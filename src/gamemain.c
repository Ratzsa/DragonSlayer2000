#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"
#include "charactertest.h"
#include "controller.h"
#include "gamemain.h"
#include "spriteoperations.h"
#include "gameareas.h"
#include "splashscreens.h"

void gameMain(uint8_t *receivedControls)
{
    Character hero = { 0 };
    Controller gameControls = { 0 };
    bool inGame = true;
    // bool heroIsAlive = true;
    uint8_t oldControls = *receivedControls;
    uint8_t heroMove = 0;
    uint8_t nextMove = 0;
    uint32_t timeBetweenMovement = HAL_GetTick();
    hero.areaCode = 7;
    hero.locationX = 2;
    hero.locationY = 5;
    hero.characterModel = 0;
    hero.health = 3;

    bool stuckInASplash = true;

    drawTitleScreen();
    while(stuckInASplash)
    {
        convertControls(&gameControls, *receivedControls);
        if(gameControls.green || gameControls.red || gameControls.yellow || gameControls.shoulder)
        {
            stuckInASplash = false;
        }
    }

    ssd1306_Fill(Black);

    drawLandscape(hero.areaCode);
    drawCharacter(&hero);
    drawHealth(hero.health);

    ssd1306_UpdateScreen();

    while(inGame)
    {
        if(hero.health < 1)
        {
            inGame = false;
            stuckInASplash = true;
            drawGameOverScreen();
            HAL_Delay(250);
            while(stuckInASplash)
            {
                convertControls(&gameControls, *receivedControls);
                if(gameControls.green || gameControls.red || gameControls.yellow || gameControls.shoulder)
                {
                    stuckInASplash = false;
                }
            }
        }

        if(hero.slayedMonsters >= 14)
        {
            inGame = false;
            stuckInASplash = true;
            drawWinScreen();
            HAL_Delay(250);
            while(stuckInASplash)
            {
                convertControls(&gameControls, *receivedControls);
                if(gameControls.green || gameControls.red || gameControls.yellow || gameControls.shoulder)
                {
                    stuckInASplash = false;
                }
            }

            stuckInASplash = true;
            drawHeroScreen();
            HAL_Delay(250);
            while(stuckInASplash)
            {
                convertControls(&gameControls, *receivedControls);
                if(gameControls.green || gameControls.red || gameControls.yellow || gameControls.shoulder)
                {
                    stuckInASplash = false;
                }
            }
        }

        if(*receivedControls != oldControls)
        {
            convertControls(&gameControls, *receivedControls);
            oldControls = *receivedControls;
            nextMove = setMovement(&gameControls, &hero);
        }

        if(HAL_GetTick() - timeBetweenMovement > 100)
        {
            heroMove = checkCollision(&nextMove, &hero);
            if(heroMove > 8)
            {
                drawFullSprite(hero.locationX, hero.locationY, CAT_FILLSQUARE, 2);
                heroMove -= 11;
            }
            else
            {
                drawFullSprite(hero.locationX, hero.locationY, CAT_FILLSQUARE, 0);
            }
            moveCharacter(&hero, &heroMove);
            if(heroMove > 4 && heroMove < 9)
            {
                drawLandscape(hero.areaCode);
            }
            drawFullSprite(hero.locationX, hero.locationY, CAT_HERO, hero.characterModel);
            heroMove = 0;
            nextMove = 0;
            timeBetweenMovement = HAL_GetTick();
        }

        ssd1306_UpdateScreen();
    }

    resetWorld();
}