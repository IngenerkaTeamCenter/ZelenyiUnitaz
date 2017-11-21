#pragma once

#include "TXLib.h"
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

    map_file.close();
}
