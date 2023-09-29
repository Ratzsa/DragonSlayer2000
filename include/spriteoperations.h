#ifndef __SPRITE_OPERATIONS_H
#define __SPRITE_OPERATIONS_H

#include <stdint.h>
#include "sprites.h"
#include "gamemain.h"
#include "charactertest.h"

void drawSpriteLine(uint8_t startX, uint8_t startY, uint16_t row);
void drawFullSprite(uint8_t startX, uint8_t startY, uint8_t category, uint8_t sprite);
void drawLandscape(uint8_t areaCode);
uint8_t getRandomSprite(uint8_t category);

#endif