#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#define GREEN 0
#define RED 1
#define YELLOW 2
#define SHOULDER 3
#define LEFT 4
#define RIGHT 5
#define DOWN 6
#define UP 7

typedef struct
{
    uint8_t up;
    uint8_t down;
    uint8_t right;
    uint8_t left;
    uint8_t shoulder;
    uint8_t yellow;
    uint8_t red;
    uint8_t green;
} Controller;

void convertControls(Controller *controlsToSet, uint8_t receivedControls);

#endif