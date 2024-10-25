#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n,m;
    cout<<"N: ";
    cin>>n;
    cout<<"M: ";
    cin>>m;

    int **tab = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = new int[m];
        for(int j = 0; j<m; j++){
            tab[i][j] = i*m + j+1;
        }
    }
    int **second_tab = new int *[m];
        for (int i = 0; i < m; i++)
    {
        second_tab[i] = new int[n];
        for(int j = 0; j<n; j++){
            second_tab[i][j] = tab[j][i];
        }
    }
    cout<<"A: "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<setw(6)<<tab[i][j];
        }
        cout<<endl;
        
    }
    for (int i = 0; i < n; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
    cout<<"B: "<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<setw(6)<<second_tab[i][j];
        }
        cout<<endl;
        
    }
    for (int i = 0; i < m; i++)
    {
        delete [] second_tab[i];
    }
    delete [] second_tab;
    return 0;
}