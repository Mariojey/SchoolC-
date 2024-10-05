#include <iostream>

using namespace std;

bool isPrime(int a){
    if (a == 1)
    {
        return false;
    }else if(a==2){
        return true;
    }
    else{
bool isPrimeNumber = true;
for (int i=2; i<=a/2; i++){
    if (a % i == 0)
    {
        isPrimeNumber = false;
    }
    
}
    return isPrimeNumber;
    }
    
}

int main(){
    int n;
    cin>>n;
    int * numbers = new int[n];
    for(int j=0; j<n; j++){
        cin>>numbers[j];
    }
    for(int i = 0; i<n; i++){
        if (isPrime(numbers[i]) == true)
        {
            cout<<"TAK"<<endl;
        }else{
            cout<<"NIE"<<endl;
        }
        
    }
}