#include <iostream>

using namespace std;

bool czy_pierwsza(int n){
    bool isPrime = true;
    if (n == 1 || n == 2)
    {
        return true;
    }else if(n == 0){
        return false;
    }else{
    
    for (int i = 2; i < n/2; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
        }
        
    }
    }
    return isPrime;
    
}

int main(){
    int n=0;
    cin>>n;
    if (czy_pierwsza(n) == true)
    {
        cout<<"Liczba pierwsza"<<endl;
    }else{
        cout<<"Nie"<<endl;
    }
    

    return 0;
}