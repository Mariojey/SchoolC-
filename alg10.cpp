#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n,m;
    cout<<"N: ";
    cin>>n;
    cout<<"M: ";
    cin>>m;
    int ** tab = new int * [n];
    for (int index = 0; index<n;index++){
        int * empty = new int [m];
        tab[index] = empty;
    }
    int top=0,right=m-1,bottom=n-1,left=0;
    int i=1;
    while (top<=bottom && left<=right && i <= n*m)
    {
        for (int c = left; c <= right; c++)
        {
            tab[top][c] = i;
            i++;
        }
        top++;
        for(int r = top; r <= bottom; r++){
            tab[r][right] = i;
            i++;
        }
        right--;
        if(top<=bottom){
                    for(int c = right; c >= left; c--){
                tab[bottom][c] = i;
                i++;
            }
            bottom--;
        }
        if(left<=right){
            for(int r = bottom; r >= top; r--){
                tab[r][left] = i;
                i++;
            }
            left++;
        }
        
    }
    for(int r = 0; r <n; r ++){
        for(int c =0; c < m; c++){
            cout<<setw(6)<<tab[r][c];
        }
        cout<<endl;
    }
    for(int i=0; i<n; i++){
        delete [] tab[i];
    }
    delete [] tab;
    return 0;
}
    //  1     2     3     4
    // 12    13    14     5
    // 11    16    15     6
    // 10     9     8     7