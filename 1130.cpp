#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

void gwiazki(int a)
{
    for (int i = 0; i < a; ++i) cout << '*';
    cout << endl;
}
void hashe(int a)
{
    for (int i = 0; i < a; ++i) cout << '#';
    cout << endl;
}

int main()
{
    ofstream plik;
    plik.open("obrazek.pgm", ios::out | ios::binary);

    if(!plik.is_open())
    {
        cout << "Nie udało się otworzyć pliku do zapisu.\n";
        return 1;
    }
    cout << "Mam otwarty plik\n";

    int wys = 10, szer = 20;
    plik << "P5\n" << szer << " " << wys << endl;
    plik << "255\n";

    for (int i = 0; i < wys*szer; ++i)
    {
        // plik.put(i % 3 * 127);
        plik << (u_char)(i % 3 * 127);
    }

    plik.close();

    gwiazki(8);
    hashe(5);

    void (*wskaznik)(int);
    wskaznik = gwiazki;
    wskaznik(9);
    wskaznik = hashe;
    wskaznik(4);

    int M = 5, N = 6;
    int * tab_1d = new int[M];
    delete [] tab_1d;

    int tab_2ds[5][6];

    int ** tab_2d = new int*[M];
    for (int i = 0; i < M; ++i)
    {
        tab_2d[i] = new int[N];
    }


    for (int i = 0; i < M; ++i)
    {
        delete [] tab_2d[i];
    }
    delete [] tab_2d;




    return 0;
}
