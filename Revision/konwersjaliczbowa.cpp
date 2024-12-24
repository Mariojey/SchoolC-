#include <iostream>

using namespace std;

void toBinary(int n){
  if(n>1){
    toBinary(n/2);
  }
  cout<<n%2;
}

void toFive(int n){
  if(n>5){
    toFive(n/5);
  }
  cout<<n%5;
}

void toSeven(int n){
  if(n>7){
    toSeven(n/7);
  }
  cout<<n%7;
}

void toEight(int n){
  if(n>8){
    toEight(n/8);
  }
  cout<<n%8;
}

void toHex(int n){
  string hexChars = "0123456789ABCDEF";
  if(n>16){
    toHex(n/16);
  }
  cout<<hexChars[n%16];
}

int main(){
  int n;
  cin>>n;
  cout<<"Binarnie: ";toBinary(n);cout<<endl;
  cout<<"Piątkowo: ";toFive(n);cout<<endl;
  cout<<"Siódemkowo: ";toSeven(n);cout<<endl;
  cout<<"Ósemkowo: ";toEight(n);cout<<endl;
  cout<<"Szesnastkowo: ";toHex(n);cout<<endl;
  return 0;
}
