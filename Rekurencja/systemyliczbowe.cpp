#include <iostream>

using namespace std;

void bin(int n){
    if(n>1){
        bin(n/2);
    }
    cout<<n%2;
}

void five(int n){
    if(n>5){
        five(n/5);
    }
    cout<<n%5;
}

void seven(int n){
    if(n>7){
        seven(n/7);
    }
    cout<<n%7;
}

void okta(int n){
    if(n>8){
        okta(n/8);
    }
    cout<<n%8;
}

void hexa(int n){
    if(n>16){
        hexa(n/16);
    }
    switch (n%16)
    {
    case 10:
        cout<<"A";
        break;
    case 11:
        cout<<"B";
        break;
    case 12:
        cout<<"C";
        break;
    case 13:
        cout<<"D";
        break;
    case 14:
        cout<<"E";
        break;
    case 15:
        cout<<"F";
        break;
    default:
        cout<<n%16;
        break;
    }
}


int main(){
    int n;
    cout<<"N: "; cin>>n;
    cout<<"Binarnie: ";bin(n);cout<<endl;
    cout<<"Piątkowo: ";five(n);cout<<endl;
    cout<<"Siódemkowo: ";seven(n);cout<<endl;
    cout<<"Ósemkowo: ";okta(n);cout<<endl;
    cout<<"Szesnastkowo: ";hexa(n);cout<<endl;

    return 0;
}

// 24 12 0
// 12 6 0
// 6 3 0
// 3 1 1
// 1 0 1
// 0

//17 3 2
//3 0 3
//