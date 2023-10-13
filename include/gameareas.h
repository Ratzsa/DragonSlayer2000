#ifndef __GAME_AREAS_H
#define __GAME_AREAS_H

#include <stdint.h>
#include "charactertest.h"

typedef uint8_t pointerArray[9][7][10];
typedef uint8_t pointerToArray[7][10];

uint8_t checkCollision(uint8_t *suggestedMove, Character *heroPosition);
uint8_t getArea(uint8_t areaCode, uint8_t getY, uint8_t getX);
void changeArea(uint8_t areaCode, uint8_t getY, uint8_t getX, uint8_t category);
void resetWorld();

#endif