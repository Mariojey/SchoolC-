//CHOINKA
#include <iostream>

using namespace std;

int main(){
    int wysokosc;
    cin>>wysokosc;
    cout<<"Wysokość: "<<wysokosc<<endl;
    for(int i=0; i<wysokosc; i++){
        for(int j=0; j<(wysokosc*2)-1; j++){
            if (j+1<(wysokosc-i))
            {
                cout<<" ";
            }else if(j+1>(wysokosc+i)){
                cout<<" ";
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}


//      *
//     ***  
//    *****
//   ******* 
//  *********
// ***********