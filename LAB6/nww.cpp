// 20 12
// 20 24
// 40 24
// 40 36
// 40 48
// 60 48
// 60 60

#include <iostream>

using namespace std;

int nww(int a, int b){
    int start_a = a, start_b = b;
    while (a!=b)
    {
        if (a>b)
        {
            b = b + start_b;
        }else if(a<b){
            a = a + start_a;
        }
    }
    return a;
    

}

int main(){
    int a,b;
    cin>>a;
    cout<<endl;
    cin>>b;
    cout<<endl;
    cout<<"Najmniejsza wspólna wielokrotność liczb "<<a<<" i "<<b<<" to "<<nww(a,b)<<endl;
    return 0;
}