// 20 12
// 8 12
// 8 4
// 4 4

#include <iostream>

using namespace std;

int nwd(int a, int b){
    while (a!=b)
    {
        if (a>b)
        {
            a = a - b;
        }else if(a<b){
            b = b - a;
        }
        
    }
    return a;
    
}

int main(){
    int a,b;
    cin>>a;
    cin>>b;
    cout<<nwd(a,b)<<endl;
    return 0;
}