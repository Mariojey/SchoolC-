#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<"Bity: ";
    for (int i = 31; i >= 0; i--)
    {
        int wartosc_bitowa = (n >> i) & 1;
        cout<<wartosc_bitowa;
    }
    
    
    
    return 0;
}

// 12 % 2 = 0
// 12 / 2 = 6
// 6 % 2 = 0
// 6 / 2 = 3
// 3 % 2 = 1
// 3 / 2 = 1
// 1 % 2 = 1
// 1 / 2 = 0