#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    cin>>n;
    bool isNegative = (n<0) ? true : false;
    if (isNegative == true)
    {
        n = abs(n);
        string result = "";
        while (n>0)
        {
            int modulo = n%2;
            char value = static_cast<char>('0' + modulo);
            result = value + result;
            n = n / 2;
        }
        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] == '0')
            {
                result[i] = '1';
            }else if(result[i] == '1'){
                result[i] = '0';
            }
        }
        cout<<result;

    }else if(isNegative == false){
        string result = "";
        while (n>0)
        {
            int modulo = n%2;
            char value = static_cast<char>('0' + modulo);
            result = value + result;
            n = n / 2;
        }
        cout<<result;
        
    }
    
    return 0;
}

// 12 % 2 = 0
// 6 % 2 = 0
// 3 % 2 = 1
// 1 % 2 = 1