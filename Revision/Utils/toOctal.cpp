#include <iostream>

using namespace std;

void toOctal(int n){
 if(n>7){
   toOctal(n/8);
 }
 cout<<n%8;
}

int main() {
  int n;
  cin >> n;
  cout<<endl;
  toOctal(n);
}
