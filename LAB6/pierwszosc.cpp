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
    if (n == 1)
    {
        cout<<"Liczba nie jest liczbą ani pierwszą ani złożoną";
    }else{
            if (isPrime(n) == true)
    {
        cout<<"Liczba jest liczbą pierwszą";
    }else{
        cout<<"Liczba jest liczbą złożoną";
    }
    }
    
    
    
    return 0;
}