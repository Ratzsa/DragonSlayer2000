#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "controller.h"
#include "gamemain.h"

void convertControls(Controller *controlsToSet, uint8_t receivedControls)
{
    controlsToSet->green = ((receivedControls >> 0) & 1);
    controlsToSet->red = ((receivedControls >> 1) & 1);
    controlsToSet->yellow = ((receivedControls >> 2) & 1);
    controlsToSet->shoulder = ((receivedControls >> 3) & 1);
    controlsToSet->left = ((receivedControls >> 4) & 1);
    controlsToSet->right = ((receivedControls >> 5) & 1);
    controlsToSet->down = ((receivedControls >> 6) & 1);
    controlsToSet->up = ((receivedControls >> 7) & 1);
}