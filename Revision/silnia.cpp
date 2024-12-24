#include <iostream>

using namespace std;

long long silnia(int n, long long tab[]){
  if (n<10 && tab[n]!=0) {
    return tab[n];
  }else {
    if(n==0) return 1;
    else return n*silnia(n-1, tab);
  }
}

int main(){
  long long strongValues[10] = {0,0,0,0,0,0,0,0,0,0};
  int n;
  cin>>n;
  if(n<0){
    cout<<"N musi być nieujemne"<<endl;
  }else {
    cout<<"Silnia = "<<silnia(n, strongValues)<<endl;
  }
  return 0;
}
