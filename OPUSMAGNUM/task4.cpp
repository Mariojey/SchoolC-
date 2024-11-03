//Ćwiczenie polega na otwarciu pliku tekstowego i wyświetleniu linijek teksu zapisanego w nim.
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream file("chemia.txt");
    while (!file.eof())
    {
        string line = "";
        getline(file, line);
        cout<<line<<endl;
    }
    
    return 0;
}