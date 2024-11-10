#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

void f1(int a)
{
    cout << "a = " << a << endl;
}
void f2(int a)
{
    cout << "a * a = " << a*a << endl;
}
using typ_wskaznikowy = void(*)(int);

int main()
{
    // void (*wskaznik)(int);
    // typ_wskaznikowy wsk = f1;
    // wsk(2);
    // wsk = f2;
    // wsk(2);
    //
    // f1(10);
    //
    // wskaznik = f1;
    // wskaznik(10);
    //
    // wskaznik = f2;
    // wskaznik(10);

    ofstream plik;
    plik.open("obrazek.pgm", ios::out | ios::binary);
    if(!plik.is_open())
    {
        cerr << "Plik się nie otworzył\n";
        return 1;
    }
    cout << "Mamy plik :)\n";

    int wysokosc = 10, szerokosc = 20;
    plik << "P5\n" << szerokosc << " " << wysokosc << "\n255\n";

    for (int w = 0; w < wysokosc; ++w)
    {
        for (int k = 0; k < szerokosc; ++k)
        {
            plik.put((w+k) % 3 * 127);
        }
    }

    plik.close();


    cout << fixed << setprecision(6);

    cout << 2.34567890 << endl;
}
