#include <iostream>

using namespace std;

void toBinaryRecursion(int n){
  if(n>1){
    toBinaryRecursion(n/2);
  }
  cout<<n%2;
}

int main(){
  int n;
  cin>>n;
  cout<<endl;
  toBinaryRecursion(n);
}
