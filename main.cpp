#include <iostream>
#include "Lib\\TXLib.h"

struct Mebel {
    int x;   //расположение по x
    int y;   //расположение по y
    int o;   //тип объекта (шкаф, стол)
    int v;   //вид объекта (красный шкаф, сломанный шкаф)
};

struct Knopka {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    HDC kartinka;
};

const int GAME_MODE = 1;
const int REDACTOR_MODE = 100;

int mode = GAME_MODE;

void Level_1 (HDC TV, HDC Chair, HDC Table, HDC Bed)
{
      txBitBlt (txDC(), 200, 200, 30, 30, TV);
      txBitBlt (txDC(), 200, 400, 30, 30, TV);
      txBitBlt (txDC(), 400, 200, 30, 30, TV);
      txBitBlt (txDC(), 300, 200, 30, 30, Chair);
      txBitBlt (txDC(), 200, 300, 30, 30, Chair);
      txBitBlt (txDC(), 300, 300, 30, 30, Chair);
      txBitBlt (txDC(), 600, 200, 30, 30, Table);
}

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

int main()
{

    txCreateWindow(800,720);

    HDC tv = txLoadImage ("Icons\\tv.bmp");

    HDC chair = txLoadImage ("Icons\\стул.bmp");

    HDC  TV = txLoadImage ("Icons\\телевизор.bmp");
    HDC  Chair = txLoadImage ("Icons\\стул.bmp");
    HDC  Table = txLoadImage ("Icons\\стол.bmp");
    HDC  Bed = txLoadImage ("Icons\\кровать.bmp");

    Knopka knopki_dlya_menu[10];
    knopki_dlya_menu[0] = {0, 0, "vanna", -1, tv};
    knopki_dlya_menu[1] = {200, 0, "zal", -1, tv};
    knopki_dlya_menu[2] = {400, 0, "kuxnua", -1, tv};
    knopki_dlya_menu[3] = {600, 0, "spalnua", -1, tv};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(RGB(112, 146, 190));
        txClear();

        Level_1 (TV, Chair, Table, Bed) ;

        for (int nomer_knopki = 0;
             nomer_knopki < 4;
             nomer_knopki++)
        {
            draw_button(knopki_dlya_menu[nomer_knopki]);
            btn_click (&knopki_dlya_menu[nomer_knopki]);
        }

        if (knopki_dlya_menu[0].risovatKartinku == 1)
        {
            txBitBlt (txDC(), 500, 500, 30, 30, knopki_dlya_menu[0].kartinka, 0, 0);
        }

         if (risovatKartinku2 == 1)
        {
            txBitBlt (txDC(), 500, 600, 30, 30, chair, 0, 0);
        }

        txSleep (10);
        txEnd();
    }

    for (int nomer_knopki = 0; nomer_knopki < 1; nomer_knopki++)
    {
        txDeleteDC (knopki_dlya_menu[nomer_knopki].kartinka);
    }

    txDeleteDC (tv);
    txDeleteDC (chair);
    txDeleteDC (TV);
    txDeleteDC (Chair);
    txDeleteDC (Table);
    txDeleteDC (Bed);

    return 0;
}
