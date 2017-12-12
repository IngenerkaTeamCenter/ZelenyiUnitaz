#include "TXLib.h"

void debug_function(int x, int y, int chislo)
{
    char str[100];
    sprintf(str, "%d", chislo);  //Writing car_x_coord value to str
    txTextOut(x, y, str);
}
