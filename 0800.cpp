#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream plik;
    plik.open("lab4/lokomotywa.txt", ios::in);

    if (!plik.is_open())
    {
        cout << "Nie można otworzyć pliku\n";
        return 1;
    }

    string tekst;
    plik >> tekst;
    cout << "tekst = " << tekst << endl;
    plik >> tekst;
    cout << "tekst = " << tekst << endl;
    string linia;
    getline(plik, linia);
    cout << "linia = " << linia << endl;
    while(!plik.eof())
    {
        getline(plik, linia);
        cout << "linia = " << linia << endl;


    }

    plik.close();

    return 0;
}
