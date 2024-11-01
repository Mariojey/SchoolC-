#include <iostream>
// 1 2 3 0 5 0 7 0 0
using namespace std;

int main(){
    int n = 0;
    cin>>n;
    int * tab = new int[n];
    for (int i = 1; i < n; i++)
    {
        tab[i] = i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 2; j < n; j++)
        {
            if (tab[i] != j && tab[i] % j == 0)
            {
                tab[i] = 0;
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<tab[i]<<endl;
    }
    
    
    
    

    delete [] tab;
    return 0;
}