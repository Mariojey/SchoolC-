#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int a;
    cin>>a;
    string converted_a = "";
    while (a>0)
    {
        converted_a = static_cast<char>(a%10) + converted_a;
        a = a / 10;
    }
    cout<<converted_a<<endl;
    string x = "x";
    string y = "y";
    cout<<x+y<<endl;
    return 0;
}