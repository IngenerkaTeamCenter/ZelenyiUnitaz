struct Mebel {
    int x;   //ðàñïîëîæåíèå ïî x
    int y;   //ðàñïîëîæåíèå ïî y
    //int o;   //òèï îáúåêòà (øêàô, ñòîë)
    //int v;   //âèä îáúåêòà (êðàñíûé øêàô, ñëîìàííûé øêàô)
    int shirina;
    HDC kartinka;
    int width;
};



const int GAME_MODE = 1;
const int REDACTOR_MODE = 100;

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
