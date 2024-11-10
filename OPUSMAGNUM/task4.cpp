//Ćwiczenie polega na otwarciu pliku tekstowego i wyświetleniu linijek teksu zapisanego w nim.
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream file("chemia.txt");
    ofstream file2("algebra.txt");
    while (!file.eof())
    {
        string line = "";
        getline(file, line);
        cout<<line<<endl;
    }
    file2<<"Wyznacznik macierzy można obliczyć przez rozwinięcie La'Placea";
    
    return 0;
}