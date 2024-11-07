// 1 2 3 4 5 6 7 8 9

#include <iostream>

using namespace std;

bool isPrime(int n){
    bool czy_pierwsza = true;
    if (n == 1)
    {
        return false;
    }else if(n == 2){
        return true;
    }else if(n==4){
        return false;    
    }else{
            
    for (int i = 2; i < n/2; i++)
    {
        if (n % i == 0)
        {
            czy_pierwsza = false;
        }
        
    }
    return czy_pierwsza;
    }
    
}

int main(){
    int n;
    cin>>n;
    cout<<endl;
    int * tab = new int[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = i+1;
    }
    for (int i = 0; i < n; i++)
    {
        if (isPrime(tab[i]) == false)
        {
            tab[i] = 0;
        }
    }
    cout<<"Liczby pierwsze do "<<n<<" to:";
    for (int i = 0; i < n; i++)
    {
        if (tab[i] != 0)
        {
            cout<<" "<<tab[i];
        }
        
    }

    delete [] tab;
    
    
    
    return 0;
}