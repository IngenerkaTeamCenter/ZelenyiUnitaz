#pragma once

#include "TXLib.h"

void roundCoords (Mebel* kartinca, int x, int y)
{
    kartinca->x = round((30/2+x)/30)*30;
    kartinca->y = round((30/2+y)/30)*30;
 }
