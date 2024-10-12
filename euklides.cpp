#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin>>a;
    cin>>b;
    int plainA = a, plainB = b;
    cout<<"Podaj liczbę naturalną a = "<<a<<endl;
    cout<<"Podaj liczbę naturalną b = "<<b<<endl;
    while (a!=b)
    {
        if (a>b)
        {
            a=a-b;
        }else if(a<b){
            b=b-a;
        }
        
    }
    cout<<"Największy wspólny dzielnik liczb "<<plainA<<" i "<<plainB<<" to "<<a<<endl;
    
}