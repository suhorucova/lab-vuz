#include <iostream>
#include "square1.h"
#include "square2.h"
#include "square4.h"
#include "squarekr.h"
#include "squarem.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    bool k = false;
    do {
        double a1, a2, a3, a4, b1, b2, r;
        cout << "Введите размеры участка." << endl;
        cout << "a1 = "; cin >> a1;
        cout << "a2 = "; cin >> a2;
        cout << "a3 = "; cin >> a3;
        cout << "a4 = "; cin >> a4;
        cout << "Введите размеры пруда." << endl;
        cout << "b1 = "; cin >> b1;
        cout << "b2 = "; cin >> b2;
        cout << "r = "; cin >> r;
        double stav1, stav2;
        cout << "Введите налоговую ставку на землю. stav1 = "; cin >> stav1;
        cout << "Введите налоговую ставку на пруды. stav2 = "; cin >> stav2;
        if (a1 <= 0 || b1 <= 0 || a2 <= 0 || b2 <= 0 || a3 <= 0 || a4 <= 0 || r <= 0 || stav1 <= 0 || stav2 <= 0)
        {
            cout << "Введите размеры заново" << endl;
        }
        else
        {
            k = true;
            //площадь пруда
            double S1 = square1(b1, b2);
            double Sm = squarem(r);
            double Skr = squarekr(r);
            double Sv = S1 - 4 * Sm + 4 * Skr;
            //площадь земли
            double S2 = square2(a1, a2);
            double S4 = square4(a3, a4);
            double Sz = S2 - S4;
            double sumz = Sz * stav1;
            double sumw = Sv * stav2;
            double S = sumz + sumw;
            cout << "Налог на землю составляет: " << sumz << endl;
            cout << "Налог на воду составляет: " << sumw << endl;
            cout << "Суммарный налог составляет: " << S << endl;
        }
    } while (k == false);
    cin.get(); cin.get();
    return 0;
}
