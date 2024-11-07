// 1 2 3 4 5 6 7 8 9

#include <iostream>

using namespace std;



int main(){
    
    int n;
    cin>>n;
    int * tab = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>tab[i];
    }
    int szukana;
    cin>>szukana;
    int poczatek = 0, koniec = n, srodek = n/2;
    while (poczatek != koniec)
    {
        if (tab[srodek] < szukana)
        {
            poczatek = srodek;
            srodek = (koniec+poczatek) / 2;
        }else if(tab[srodek] > szukana){
            koniec = srodek;
            srodek = (koniec+poczatek) / 2;
        }else{
            cout<<"Liczba "<<szukana<<" znajduje się w polu o indeksie "<< srodek;
            break;
        }
    }
    if (poczatek==koniec && tab[srodek] != szukana)
    {
        cout<<"Podanej liczby "<<szukana<<" nie ma w tablicy";
    }
    
    return 0;
}