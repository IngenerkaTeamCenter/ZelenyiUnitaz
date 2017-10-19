#include <iostream>
#include "Lib\\TXLib.h"

/*
1) ��������� ��� ������ (� ������� ���� ��� � ��������)
2) ���������� ����
3) ������� ������� �� ������ ��������
4) �������� ������ �������� �� ������� �� ������ ������
*/

using namespace std;

struct Mebel {
    int mx;   //������������ �� x
    int my;   //������������ �� y
    int mo;   //��� ������� (����, ����)
    int mv;   //��� ������� (������� ����, ��������� ����)
};

struct Button {
    int bx;
    int by;
    int bt;
    int bp;


};

const int GAME_MODE = 1;
const int REDACTOR_MODE = 100;

int mode = GAME_MODE;

void draw_button(int x, int y, const char* text)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB(255, 255, 255));
    txSelectFont("Times New Roman", 25);
    txRectangle(x, y,400,100);
    txTextOut(x + 40, y + 40, text);
}

int main()
{
    txCreateWindow(800,720);

    int risovatKartinku = -1;
    HDC tv = txLoadImage ("Icons\\���������.bmp");


  //  int risovatKartinku = 1;
    HDC du = txLoadImage ("Icons\\�������.bmp");

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        draw_button(0, 0, "���������");
        draw_button(200, 0, "����");

        if (txMouseButtons() & 1
            && txMouseX() >= 0
            && txMouseX() <= 200
            && txMouseY() >= 0
            && txMouseY() <= 100)
        {
            risovatKartinku = -risovatKartinku;
            txSleep(100);
        }
        if (txMouseButtons() & 1
            && txMouseX() >= 200
            && txMouseX() <= 200
            && txMouseY() >= 0
            && txMouseY() <= 100)
        {
            risovatKartinku = risovatKartinku;
            txSleep(100);
        }

        if (risovatKartinku == 1)
        {
            txBitBlt (txDC(), 500, 500, 30, 30, tv, 0, 0);
        }

        txSleep (10);
        txEnd();
    }

    txDeleteDC (tv);
    txDeleteDC (du);

    return 0;
}
