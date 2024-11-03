// Celem zadania jest narysowanie w konsoli ślimaka liczbowego, każda liczba powinna wyświetlać się na czterech pozycjach.
// 1 2 3 4 5
//         6
//         7
//         8
//         9

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int ** tab = new int * [n];
    for (int i = 0; i < n; i++)
    {
        int * empty = new int[m];
        tab[i] = empty;
    }
    int top = 0, left = 0, bottom = n - 1, right = m - 1;
    int index = 1;
    while (top<=bottom && left <= right && index <= n*m )
    {
        if (top<bottom)
        {
            for (int i = left; i <= right; i++)
            {
                tab[top][i] = index;
                index += 1;
            }
            top++;
            
        }
        if (left<right)
        {
            for (int i = top; i <= bottom; i++)
            {
                tab[i][right] = index;
                index++;
            }
            right--;
            
        }
        if (top<=bottom)
        {
            for (int i = right; i >= left; i--)
            {
                tab[bottom][i] = index;
                index++;
            }
            bottom--;
        }
        if(left<=right){
            for (int i = bottom; i >= top; i--)
            {
                tab[i][left] = index;
                index++;
            }
            left++;  
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<setw(4)<<tab[i][j];
        }
        cout<<endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
    
    
    
    return 0;
}