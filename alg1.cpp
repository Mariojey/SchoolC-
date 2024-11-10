#include <iostream>

using namespace std;

int convert(const char* text){
    int i = 0;
    int value = 0;
    int sign = 1;

    if (text[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for(; text[i] != '\0'; ++i){
        value = value * 10 + (text[i] - '0');
    }
    return sign * value;
    
}

int main(int argc, char* argv[]){
    int sum_p = 0;
    int sum_np = 0;
    for(int i = 1; i < argc; i++){
        int l = convert(argv[i]);
        cout<<l<<endl;
        if(l % 2 == 0){
            sum_p += l;
        }else if(l % 2 != 0){
            sum_np += l;
        }
    }
    cout<<"Suma liczb parzystych = "<<sum_p<<endl;
    cout<<"Suma liczb nieparzystych = "<<sum_np<<endl;
}
