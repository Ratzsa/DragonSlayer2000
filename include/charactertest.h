#ifndef __CHARACTER_TEST_H
#define __CHARACTER_TEST_H

#include <stdint.h>
#include "controller.h"

typedef struct
{
    uint8_t locationX;
    uint8_t locationY;
    uint8_t characterModel;
    uint8_t areaCode;
}Character;

uint8_t setMovement(Controller *inGameControls, Character *heroLocation);
void drawCharacter(Character *heroDraw);
void moveCharacter(Character *heroMove, uint8_t *movement);

#endif