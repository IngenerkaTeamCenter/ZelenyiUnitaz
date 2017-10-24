#include <iostream>
#include "Lib\\TXLib.h"

/*
1) Ñòðóêòóðà äëÿ êíîïêè (â êîòîðîé åñòü åù¸ è êàðòèíêà)
2) Íîðìàëüíîå ìåíþ
3) Ñäåëàòü íàæàòèå íà êíîïêó ôóíêöèåé
4) Âûâîäèòü ðàçíûå êàðòèíêè ïî íàæàòèþ íà ðàçíûå êíîïêè
*/

using namespace std;

struct Mebel {
    int x;   //ðàñïîëîæåíèå ïî x
    int y;   //ðàñïîëîæåíèå ïî y
    int o;   //òèï îáúåêòà (øêàô, ñòîë)
    int v;   //âèä îáúåêòà (êðàñíûé øêàô, ñëîìàííûé øêàô)
};

struct Knopka{
    int x;
    int y;
    const char* text;

};

const int GAME_MODE = 1;
const int REDACTOR_MODE = 100;

int mode = GAME_MODE;

void draw_button(Knopka k)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB( 195, 195, 195));
    txSelectFont("Times New Roman", 25);
    txRectangle(k.x,k.y,k.x+200,k.y+100);
    //txTextOut(k.x, k.y + 40, k.text);
    txDrawText(k.x, k.y + 40, k.x + 200, k.y + 100, k.text, DT_CENTER);

}

void btn_click (int x, int y, int xx, int yy, int* risovatKartinku)
{
    if (txMouseButtons() == 1
        && txMouseX() >= x
        && txMouseX() <= y
        && txMouseY() >= xx
        && txMouseY() <= yy)
    {
        *risovatKartinku = - *risovatKartinku;
        txSleep(100);
    }
}

int main()
{
    txCreateWindow(800,720);

    int risovatKartinku = -1;
    HDC tv = txLoadImage ("Icons\\tv.bmp");

    Knopka knopki_dlya_menu [4];

    knopki_dlya_menu[0] = {0, 0, "vanna"};
    knopki_dlya_menu[1] = {200, 0, "zal"};
    knopki_dlya_menu[2] = {400, 0, "kuxnua"};
    knopki_dlya_menu[3] = {600, 0, "spalnua"};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(RGB(112, 146, 190));
        txClear();

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);

        for (int nomer_knopki = 0;
             nomer_knopki < 4;
             nomer_knopki++)
        {
            draw_button(knopki_dlya_menu[nomer_knopki]);
        }



        if (risovatKartinku == 1)
        {
            txBitBlt (txDC(), 500, 500, 30, 30, tv, 0, 0);
        }

        txSleep (10);
        txEnd();
    }

    txDeleteDC (tv);

    return 0;
}
