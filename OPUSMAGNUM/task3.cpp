//Ćwiczenie polega na wczytaniu z wejścia kompilatora liczb i wskazanie, które z nich są parzyste
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) % 2 == 0)
        {
            cout<<argv[i]<<endl;
        }
        
    }
    
    return 0;
}