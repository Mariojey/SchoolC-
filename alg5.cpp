//SZACHOWNICA
#include <iostream>

using namespace std;

int main(){
    int rozmiar;
    cin>>rozmiar;
    bool isUnPair = true;
    cout<<"Rozmiar: "<<rozmiar<<endl;
    for (int i = 0; i < rozmiar; i++)
    {
        bool isHash = true;
        if (isUnPair == false)
        {
            isHash = false;
        }
        
        for (int j = 0; j < rozmiar; j++)
        {
            if (isHash == true)
            {
                cout<<"##";
            }else{
                cout<<"  ";
            }
            isHash = !isHash;
        }
        isUnPair = !isUnPair;
        cout<<endl;
        
    }
    return 0;
}