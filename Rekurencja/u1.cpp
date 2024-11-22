#include <iostream>
#include <cmath>

using namespace std;

void toU1(int n, bool minus, int countOfBits){

    if(!minus){
        minus = n < 0;
        n = abs(n);
    }

    if (countOfBits > 1)
    {
        toU1(n/2,minus,countOfBits-1);
    }

    if (minus)
    {
        if (n%2==0)
        {
            cout<<1;
        }else{
            cout<<0;
        }
        
    }else{
        cout<<n%2;
    }
    
    
}

int main(){
    int n;
    cout<<"N: ";cin>>n;
    cout<<"Bity: ";toU1(n,false,32);
    return 0;
}