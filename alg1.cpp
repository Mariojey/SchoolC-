#include <iostream>

using namespace std;

int main(int argc, int argv[]){
    int sum_p = 0;
    int sum_np = 0;
    for(int i = 1; i < argc; i++){
        if(argv[i] % 2 == 0){
            sum_p += 1;
        }else if(argv[i] % 2 != 0){
            sum_np += 1;
        }
    }
    cout<<"Suma liczb parzystych = "<<sum_p<<endl;
    cout<<"Suma liczb parzystych = "<<sum_np<<endl;
}
