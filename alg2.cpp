#include <iostream>

using namespace std;

int main(){
    int value_dec;
    cin>>value_dec;
    cout<<"Warto�� liczby w systemie dziesi�tnym: "<<value_dec<<endl;
    int if_two = 0, i;
    while(value_dec != 0){
        if(value_dec % 2 != 0){
            if_two ++;
        }
        value_dec = value_dec/2;
    };
    cout<<"Liczno�� jedynek w zapisie dw�jkowym: "<<if_two<<endl;
    return 0;
}
