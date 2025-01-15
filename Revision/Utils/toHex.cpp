#include <iostream>

using namespace std;

void toHex(int n){

  string chars = "0123456789ABCDEF";

  if(n>16){
    toHex(n/16);
  }

  cout<<chars[n%16];
}

int main() {
  int n;
  cin >> n;
  cout<<endl;
  toHex(n);
}
