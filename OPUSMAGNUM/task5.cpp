//Program obliczający wyznacznik macierzy metodą La Placea

#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<endl;
    int ** tab = new int * [n];
    for (int i = 0; i < n; i++)
    {
        int * empty = new int[n];
        tab[i] = empty;
    }
    
    for (int i = 0; i < n; i++)
    {
        string line = "";
        getline(cin, line);
        cout<<endl;
        int element_index = 0;
        string number_from_text = "";
        for (int element = 0; element < line.length(); element++)
        {
            if (static_cast<int>(line[element] == 32))
            {
                tab[i][element_index] = stoi(number_from_text);
                element_index ++;
                number_from_text = "";
            }else{
                number_from_text += line[element];
            }   
        }     
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cout<<tab[r][c];
        }
        cout<<endl;
        
    }      

    for (int i = 0; i < n; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
    
}