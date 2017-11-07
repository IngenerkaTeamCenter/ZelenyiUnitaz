#include "TXLib.h"
struct Mebel {
    int x;   //ðàñïîëîæåíèå ïî x
    int y;   //ðàñïîëîæåíèå ïî y
    //int o;   //òèï îáúåêòà (øêàô, ñòîë)
    //int v;   //âèä îáúåêòà (êðàñíûé øêàô, ñëîìàííûé øêàô)
    int shirina;
    HDC kartinka;
    int width;
};

struct Knopka {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    HDC kartinka;
    bool najata;
};

struct Knopka2 {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    HDC kartinka;
    bool najata;
};

void draw_button(Knopka knop)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB( 195, 195, 195));
    txSelectFont("Times New Roman", 25);
    txRectangle(knop.x,knop.y,knop.x+200,knop.y+100);
    txDrawText(knop.x, knop.y + 40, knop.x + 200, knop.y + 100, knop.text, DT_CENTER);
}

void btn_click (Knopka* knop)
{
    if (txMouseButtons() & 1
        && txMouseX() >= knop->x
        && txMouseX() <= knop->x + 200
        && txMouseY() >= knop->y
        && txMouseY() <= knop->y + 100)
    {

        knop->risovatKartinku = -knop->risovatKartinku;
        txSleep(100);
    }
}

void btn_navashdenie (Knopka* knop)
{
    if (txMouseX() >= knop->x
    && txMouseX() <= knop->x + 200
    && txMouseY() >= knop->y
    && txMouseY() <= knop->y + 100)
    {
        knop->najata = true;
    }

    if (knop->najata)
        txRectangle(knop->x, knop->y + 100, knop->x + 200, knop->y + 200);

    if (txMouseX() < knop->x
    || txMouseX() > knop->x + 200
    || txMouseY() > knop->y + 200)
    {
        knop->najata = false;
    }
}

