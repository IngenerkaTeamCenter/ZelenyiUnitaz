#include "TXLib.h"

double oneDimensionalDistance (double minX1, double maxX1, double minX2, double maxX2)
{
    double distance = 0;

    if (minX1  < maxX1 && minX2  < maxX2 &&
                maxX1  < minX2) {
        distance = minX2 - maxX1;                         //4 следующих случая - проникновения
    } else if (minX1  < minX2 && maxX1  < maxX2 &&
                minX2  < maxX1) {
        distance = 0;
    } else if (minX1  < minX2 && maxX2  < maxX1 &&
                minX2  < maxX2) {
        distance = 0;
    } else if (minX2  < minX1 && maxX1  < maxX2 &&
                minX1  < maxX1) {
        distance = 0;
    } else if (minX2  < minX1 && maxX2  < maxX1 &&
                minX1  < maxX2) {
        distance = 0;
    } else if (minX2  < maxX2 && minX1  < maxX1 &&
                maxX2  < minX1) {
        distance = minX1 - maxX2;
    }

    return distance;
}
