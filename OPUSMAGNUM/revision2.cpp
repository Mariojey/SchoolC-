//Ćwiczenie polegające na konwersji liczby zapisanej binarnie w kodzie U2 na liczbę zapisaną dziesiętnie.
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    string binary;
    cin>>binary;

    int decimal = 0;
    int binary_size = binary.size();
    bool isNegative = (binary[0] == '1');

    if (isNegative)
    {
        for (int i = 0; i < binary_size; i++)
        {
            binary[i] = (binary[i] == '0') ? '1' : '0';
        }

        //Dodanie jednyki
        bool once = true;
        for (int i = binary_size - 1; i >= 0; i--)
        {
            if (binary[i] == '1' && once)
            {
                binary[i] = '0';
            }else if(binary[i] == '0' && once){
                binary[i] = '1';
                once = false;
            }
            
        }
        
        
    }
    //Zmiana liczby binarnej na liczbę dziesiętną
    for (int i = binary_size; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, binary_size - 1 - i);
        }
        
    }

    cout<<decimal<<endl;

    return 0;
}