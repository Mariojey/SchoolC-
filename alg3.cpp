#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    string actually;
    cin>>actually;
    cout<<"Aktualna pozycja skoczka: "<<actually<<endl;
    char a1 = actually[0];
    char a2 = actually[1];
    string new_pos;
    cin>>new_pos;
    cout<<"Nowa pozycja skoczka: "<<new_pos<<endl;
    char b1 = new_pos[0];
    char b2 = new_pos[1];
    int a1c = static_cast<int>(a1) - 96;
    int a2c = a2 - '0';
        int b1c = static_cast<int>(b1) - 96;
    int b2c = b2 - '0';
    if(b1c - a1c == 2 || b1c - a1c == -2){
        if(b2c == a2c-1 || b2c == a2c+1){
            cout<<"Nowa pozycja jest ruchem prawid這wym."<<endl;
        }else{
            cout<<"Nowa pozycja jest ruchem nieprawid這wym."<<endl;
        }
    }else if(b1c - a1c == 1 || b1c - a1c == -1){
        if(b2c == a2c-2 || b2c == a2c+2){
            cout<<"Nowa pozycja jest ruchem prawid這wym."<<endl;
        }else{
            cout<<"Nowa pozycja jest ruchem nieprawid這wym."<<endl;
        }
    }else{
        cout<<"Nowa pozycja jest ruchem nieprawid這wym."<<endl;
    }
    return 0;

 //a  00000000
 //b  00000000
 //   00101000
 //   01000100
 //   00020000
 //   01000100
 //   00101000
 //   00000000
}
