//Celem zadania jest aby user podał liczbę całkowitą od 0 do 30 a program wypisuje, w której dziesiątce się znajduje

#include <iostream>

using namespace std;

int main(){
    int liczba;
    cin>>liczba;
    switch (liczba)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        cout<<"0-9"<<endl;
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
        cout<<"10-19"<<endl;
        break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
        cout<<"20-29"<<endl;
        break;
    case 30:
        cout<<"Podana liczba 30"<<endl;
        break;
    
    default:
        cout<<"Użytkownik wyszedł poza zakres"<<endl;
        break;
    }
    return 0;
}