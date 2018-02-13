#pragma once

#include "Const.cpp"
#include "TXLib.h"

void roundCoords (Mebel* kartinca, int x, int y)
{
    kartinca->x = round ( x / SHIRINA_KARTINKI ) * SHIRINA_KARTINKI;
    kartinca->y = round ( y / VYSOTA_KARTINKI ) * VYSOTA_KARTINKI;
 }
