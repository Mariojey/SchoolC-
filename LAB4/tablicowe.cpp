#include <iostream>

using namespace std;

enum Warunek {
    FIBONACCI,
    KWADRAT,
    SZESCIAN,
    SILNIA
};

void wypelnij(int * tab, int n, int range){
    
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % range + 1;
    }
}

void wypisz(int * tab, int n){
    cout<<"[";
    for (int i = 0; i < n-1; i++)
    {
        cout<<tab[i]<<", ";
    }
    cout<<tab[n]<<"]";
}

int max(int * tab, int n){
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        if(tab[i]>maximum){
            maximum = tab[i];
        }
    }
    cout<<"Maksimum: "<<maximum;
}

int min(int * tab, int n){
    int minimum = tab[0];
    for (int i = 0; i < n; i++)
    {
        if(tab[i]<minimum){
            minimum = tab[i];
        }
    }
    cout<<"Minimum: "<<minimum;
}

bool isPrime(int num){
    bool isTrue = true;
    if(num == 1 || num == 2 || num == 3){
        return isTrue;
    }else{
        for(int i = 2; i <= num/2; i++){
            if (num % i == 0)
            {
                isTrue = false;
            }
            
        }
        return isTrue;
    }
    
}

int liczby_pierwsze(int * tab, int n, int * pierwsze){
    cout<<"Liczby pierwsze: ";
    int iterator = 0;
    for(int i = 0; i < n; i++){
        if (isPrime(tab[i]) == true)
        {
            pierwsze[iterator] = tab[i];
            cout<<pierwsze[iterator]<<", ";
            iterator++;
        }
        
    }
}

int suma(int * tab, int n){
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += tab[i];
    }
    cout<<"Suma: "<<suma;   
}
bool isFib(int num){
    int a = 1, b = 1;
    while((num!=a) && (num!=b)){
        a+=b;
        b+=a;
        if(b>num) break;
    }
    if(num==a || num == b){
        return true;
    }else{
        return false;
    }
}

bool isSquare(int num){
    bool isTrue = false;
    for (int i = 1; i < num; i++)
    {
        if((num % i == 0) && (num/i == i)){
            isTrue = true;
        }
    }
    return isTrue;
    
}
bool isS(int num){
    bool isTrue = false;
    for (int i = 1; i < num; i++)
    {
        for(int j = 1; j < num; j++){
            if((num % i == 0) && (i % j == 0) && (num/i == i/j) && (isSquare(i) == true)){
                isTrue = true;
            }
        }
    }
    return isTrue;
}
long int factorial(int num){
    if (num==0)
    {
        return 1;
    }else{
        return num*factorial(num-1);
    }
    
}
bool isFactorial(int num){
    bool isTrue = false;
    for (int i = 1; i <= num; i++)
    {
        if (factorial(i)==(long)num)
        {
            isTrue = true;
        }
        
    }
    return isTrue;
    
}
void wypisz_warunkowo(int * tab, int n, Warunek w)
{
    switch (w)
    {
    case FIBONACCI:
        cout<<"Liczb z ciągu Fibonacciego: ";
        for (int i = 0; i < n; i++)
        {
            if(isFib(tab[i]) == true){
                cout<<tab[i]<<", ";
            }
        }
        
        break;
    case KWADRAT:
        cout<<"Kwadraty liczb: ";
        for (int i = 0; i < n; i++)
        {
            if(isSquare(tab[i]) == true){
                cout<<tab[i]<<", ";
            }
        }
        
        break;
    case SZESCIAN:
        cout<<"Sześciany liczb: ";
        for (int i = 0; i < n; i++)
        {
            if(isS(tab[i]) == true){
                cout<<tab[i]<<", ";
            }
        }
        
        break;
    case SILNIA:
        cout<<"Silnie liczb: ";
        for (int i = 0; i < n; i++)
        {
            if(isFactorial(tab[i]) == true){
                cout<<tab[i]<<", ";
            }
        }
        
        break;
    
    default:
        break;
    }
}

int main(){
    int seed, n, range;
    cout<<"Ziarno: ";
    cin>>seed;
    cout<<"N: ";
    cin>>n;
    cout<<"Zakres: ";
    cin>>range;
    cout<<endl;
    int *tab = new int[n];
    int *pierwsze = new int[n]{};

    srand(n);
    wypelnij(tab,n,range);
    // wypisz(tab,n);
    // cout<<endl;
    // max(tab,n);
    // cout<<endl;
    // min(tab,n);
    // cout<<endl;
    // suma(tab,n);
    // cout<<endl;
    // liczby_pierwsze(tab,n,pierwsze);
    // cout<<endl;
    // wypisz_warunkowo(tab,n,KWADRAT);
    // cout<<endl;
    // wypisz_warunkowo(tab,n,SZESCIAN);
    // cout<<endl;
    // wypisz_warunkowo(tab,n,SILNIA);
    // cout<<endl;
    // wypisz_warunkowo(tab,n,FIBONACCI);
    // cout<<endl;

    delete [] tab;
    delete [] pierwsze;
    

    return 0;
}