#include "TXLib.h"
#include <iostream>

#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fout;
    fout.open("массив.txt");

    txCreateWindow(800, 600);
    while (fout.good()) {
        string get;
        getline (fout, get);

        int pos1 = get.find(',');
        string adress = get.substr(0, pos1);
        get = get.substr(pos1 + 2);

        int pos2 = get.find(',');
        string x = get.substr(0, pos2);
        get = get.substr(pos2 + 2);

        int pos3 = get.find(',');
        string y = get.substr(0, pos3);
        get = get.substr(pos3 + 2);

        HDC pic = txLoadImage(adress.c_str());
        txBitBlt (txDC(), atoi(x.c_str()), atoi(y.c_str()), 30, 30, pic, 0, 0);
        txDeleteDC(pic);
    }
    fout.close();

}
