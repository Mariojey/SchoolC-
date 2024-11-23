//Lista kroków funkcji rekurencyjnej
// 1. Jeżeli wymiar n macierzy = 1, to wyznacznik = tab[0][0]
// 2. Jeżeli 1 == false, to niech uruchomi się pętla, która wykonuje się n razy i dla każdego tab[n][iterator]
// mnoży tab[n][iterator] * funkcja_obliczająca_wyznacznik(dla macierzy o wymiarach n-1, gdzie wyrzuconym wierszem jest wiersz n-ty).
#include <iostream>
#include <vector>

using namespace std;

void wyznacz_minor(int ** matrix, int ** minor, int size, int row, int col){
    int minorRow = 0;
    for (int i = 0; i < size; i++)
    {
        if (i != row)
        {
            int minorCol = 0;
            for (int j = 0; j < size; j++)
            {
                if(j!=col){
                    minor[minorRow][minorCol] = matrix[i][j];
                    minorCol ++;
                }
            }
            minorRow++;
            
        }
        
    }
    
}


int wyznacznik(int ** matrix, int size){
    if (size == 1)
    {
        return matrix[0][0];

    }else if(size == 2){

        return matrix[0][0] * matrix[1][1] - (matrix[0][1] * matrix[1][0]);
    
    }else{

        int determinant = 0;
        int ** minor = new int*[size-1];

        for(int i=0; i<size-1; i++){
            minor[i] = new int[size-1];
        }

        //Tworzymy minor dla każdego column - ntego elementu pierwsze wiersza macierzy

        for (int column = 0; column < size; column++)
        {
            wyznacz_minor(matrix, minor, size, 0, column);
            determinant += (column % 2 == 0 ? 1 : -1) * matrix[0][column] * wyznacznik(minor, size-1);
        }

        for (int k = 0; k < size-1; k++)
        {
            delete [] minor [k];
        }
        delete [] minor;

        return determinant;
         
    }
    
}

int main(){
    int size;

    // cout<<"Rozmiar: ";
    cin>>size;
    int ** matrix = new int * [size];
    // cout<<"Macierz: ";
    int row = 0, column = 0;
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }

    for (int row = 0; row < size; ++row) 
    { for (int column = 0; column < size; ++column) 
        { 
            cin >> matrix[row][column]; 
        }
    }
    
    // while (row<size)
    // {
    //     int number;
    //     while (cin>>number && column < size)
    //     {
    //         matrix[row][column] = number;
    //         column++;
    //     }
    //     row++;
    // }
    // row=0;column=0;
    // while (row<size)
    // {
    //     while (column<size)
    //     {
    //         cout<<matrix[row][column];
    //         column++;
    //     }
    //     cout<<endl;
    //     row++;
    // }
    
    int det = wyznacznik(matrix, size); 
    cout <<"Wyznacznik: "<< det;

    for (int i = 0; i < size; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
    
    


    return 0;
}