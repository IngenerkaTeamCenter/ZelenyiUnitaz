#pragma once

#include "TXLib.h"
#include "menu.cpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read_file()
{
    ifstream map_file;
    string stroka_s_kartinkoi;
    map_file.open("Files\\Map.txt");

    while (map_file.good()) {

        getline (map_file, stroka_s_kartinkoi);
        if (strlen(stroka_s_kartinkoi.c_str()) > 0)
        {
            int pos_adresa = stroka_s_kartinkoi.find(',');
            string adress = stroka_s_kartinkoi.substr(0, pos_adresa);

            stroka_s_kartinkoi = stroka_s_kartinkoi.substr(pos_adresa + 2);
            int pos_x = stroka_s_kartinkoi.find(',');
            string x = stroka_s_kartinkoi.substr(0, pos_x);

            stroka_s_kartinkoi = stroka_s_kartinkoi.substr(pos_x + 2);
            int pos_y = stroka_s_kartinkoi.find(',');
            string y = stroka_s_kartinkoi.substr(0, pos_y);

            HDC pic = txLoadImage(adress.c_str());
            HBITMAP hbm=(HBITMAP)Win32::GetCurrentObject(pic, OBJ_BITMAP);
            BITMAP bm;
            Win32::GetObject(hbm,sizeof(bm), (LPVOID)&bm);

            txBitBlt (txDC(), atoi(x.c_str()), atoi(y.c_str()), bm.bmWidth, bm.bmHeight, pic, 0, 0);
            txDeleteDC(pic);
        }
    }

    map_file.close();
}

void saveMassive(Mebel* KART1, int nomer_kartinki)
{
    ofstream fout_save;
    fout_save.open("Files\\savefile.txt");

    for(int i = 0; i< nomer_kartinki; i++)
    {
        if (KART1[i].risovat)
        {
            fout_save << /*KART1[i].adress << "," <<*/ KART1[i].x << "," << KART1[i].y << endl;
        }
    }

    fout_save.close();
}
