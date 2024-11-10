#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

int kwadrat(int liczba)
{
    return liczba * liczba;
}
int szescian(int liczba)
{
    return liczba * liczba * liczba;
}

int suma(int a, int b)
{
    return a + b;
}

using uchwyt = int (*)(int);

int main()
{
    // cout << kwadrat(5) << endl;
    // cout << szescian(5) << endl;
    //
    // int (*wskaznik)(int);
    // wskaznik = kwadrat;
    // cout << wskaznik(5) << endl;
    // wskaznik = szescian;
    // cout << wskaznik(5) << endl;
    //
    // uchwyt w = kwadrat;
    // cout << w(3) << endl;

    // wskaznik = suma; to nie zadziała

    ofstream plik;
    plik.open("obrazek.pgm", ios::out | ios::binary);
    if(!plik.is_open())
    {
        cout << "Nie udało się otworzyć pliku\n";
        return 1;
    }
    int szer = 512, wys = 256;
    plik << "P6\n" << szer << " " << wys << "\n255\n";

    // zapisać piksele
    for (int w = 0; w < wys; ++w)
    {
        for (int k = 0; k < szer; ++k)
        {
            // plik.put((w+k) % 3 * 127);
            // plik << (unsigned char)w ;

            plik.put(w);
            plik.put(k%256);
            plik.put(w);
        }
    }

    plik.close();


    cout << fixed << setprecision(6);

    cout << 12.3456789 << endl;

    return 0;
}
