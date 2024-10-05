#include <iostream>

using namespace std;

int factorial(int a){
    if (a<=1)
    {
        return 1;
    }else{
        return a * factorial(a-1);
    }
    
}

int main(){
    int n;
    cin>>n;
    int * numbers = new int[n];
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }
    for(int i=0; i<n; i++){
        int factorial_value = factorial(numbers[i]);
         int decimal, unical;
        while((factorial_value/10)>=100){
            factorial_value = factorial_value / 10;
        }
        decimal = factorial_value / 10;
        while((decimal / 10) >= 10){
            decimal = decimal / 10;
        }
        decimal = decimal % 10;
        unical = factorial_value % 10;
        cout<<decimal<<" "<<unical<<endl;
                //        string converted = to_string(factorial_value);
        // int decimal , unical = converted[converted.length()-1] - '0';
        // if (converted.length() == 1)
        // {
        //     decimal = 0;
        // }else{
        //     decimal = converted[converted.length()-2] - '0';
        // }
        
        // cout<<decimal<<" "<<unical<<endl;
    }
    return 0;
}
