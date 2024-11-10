#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;
    int ziarno;

    cout<<"Ziarno: ";
    cin>>ziarno;

    cout<<"N:";
    cin>>n;
    int *tab = new int[n];
    srand(ziarno);

    int * i = tab;
    int * j = tab + n;
    while (i<j)
    {
        int los = rand() % 100;
        cout<< setw(6) << los;
        *i = los;
        i++;
    }
    
    int * w = tab;
    int * end = tab + n - 1;
    cout<<endl;
    cout<<"Pary: "<<endl;
    while (w<end-1)
    {
        cout<< setw(6) << *w;
        w++;
        cout<< setw(6) << *w;
        cout<<endl;
    }
    delete [] tab;
    return 0;
}