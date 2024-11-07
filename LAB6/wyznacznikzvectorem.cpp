#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double determinant(vector<vector<double>>&matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (matrix[j][i] != 0)
                {
                    swap(matrix[i],matrix[j]);
                    break;
                }   
            }
        }
        for (int j = i + 1; j < n; ++j)
        {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; ++k)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    double det = 1;
    for (int i = 0; i < n; ++i)
    {
        det *= matrix[i][i];
    }
    return det;
    
}

int main(){
    vector<vector<double>>matrix = {
        {1,0,0},
        {0,5,1},
        {0,0,9}
    };
    cout<<"Wyznacznik:"<<determinant(matrix)<<endl;
    return 0;
}