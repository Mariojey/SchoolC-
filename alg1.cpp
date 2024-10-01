#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    int sum_p = 0;
    int sum_np = 0;
    for(int i = 1; i < argc; i++){
        int l = atoi(argv[i]);
        if(l % 2 == 0){
            sum_p += l;
        }else if(l % 2 != 0){
            sum_np += l;
        }
    }
    cout<<"Suma liczb parzystych = "<<sum_p<<endl;
    cout<<"Suma liczb parzystych = "<<sum_np<<endl;
}
