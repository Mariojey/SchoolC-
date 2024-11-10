#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;
    int ** tab = new int*[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = new int[n];
        for (int j = 0; j < n; i++)
        {
            cin>>tab[i][j];
        }   
    }
    int det = 1;
    for (int r = 0; r < n; r++)
    {
        int maksymalnaWWierszu = r;
        for (int c = r + 1; c < n; c++)
        {
            if (tab[r][c] > tab[maksymalnaWWierszu][c])
            {
                maksymalnaWWierszu = c;
            }            
        }
        if (maksymalnaWWierszu != r)
            {
                swap(tab[r], tab[maksymalnaWWierszu]);
                det = det*(-1);
            }

            if (tab[r][r] == 0)
            {
                cout<<"0"<<endl;
                break;
            }
            
            det = det * tab[r][r];

            for (int col = r; col < n; col++)
            {
                tab[r][col] = tab[r][col] / tab[r][r];
            }

            for (int row = r+1; row < n; row++)
            {
                int wspolczynnik = tab[row][r];
                for (int c = r; c < n; c++)
                {
                    tab[row][c] -= wspolczynnik * tab[r][c];
                }
                
            }   
    }
    cout<<det<<endl;
    
    // if (n==2)
    // {
    //     det = (tab[0][0] * tab[1][1]) + (tab[1][0] * tab[0][1]) - (tab[0][1]*tab[0][1]) - (tab[1][1]*tab[0][0]);
    //     cout<<"Wyznacznik: "<<det;
    // }else if(n==3){
    //     det = (tab[0][0] * tab[1][1] * tab[2][2]) + (tab[1][0] * tab[2][1] * tab[0][2]) + (tab[2][0] * tab[0][1] * tab[1][2]) - (tab[0][2] * tab[1][1] * tab[2][0]) - (tab[1][2] * tab[2][1] * tab[0][0]) - (tab[2][2] * tab[0][1] * tab[1][0]);
    //     cout<<"Wyznacznik: "<<det;
    // }else if(n==1){
    //     det = tab[0][0];
    //     cout<<"Wyznacznik: "<<det;
    // }else{
    //     for (int r = 0; r < n; r++)
    //     {
            
    //     }
        
    // }
    
    for (int i = 0; i < n; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
    
    return 0;
}

// 1 2 3 4
// 2 2 3 4
// 3 3 3 4
// 4 4 4 4