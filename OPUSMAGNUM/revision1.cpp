//Ćwiczenie polega na konwersji liczby całkowitej zapisanej dziesiętnie na kod U2.
#include <iostream>

using namespace std;

int main(){
    int a;
    cin>>a;
    cout<<"Bity:"<<endl;
    for (int i = 31; i >= 0; i--)
    {
        int res = (a >> i) & 1;
        cout<<res;
    }
    
    return 0;
}