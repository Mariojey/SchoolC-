#include <iostream>
#include <vector>
#include <string>

using namespace std;

string mnoz(string num1, string num2){
    int n = num1.size();
    int m = num2.size();

    vector<int>result(n + m,0);

    for (int i = n - 1; i>= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int mnozenie = (num1[i] - '0') * (num2[j] - '0');

            int suma = mnozenie + result[i + j + 1];
            result[i + j + 1] = suma % 10;
            result[i + j] += suma / 10;
        }
        
    }

    string resultStr;
    for (int num : result)
    {
        if (!(resultStr.empty() && num == 0))
        {
            resultStr.push_back(num + '0');
        }
    }

    return resultStr.empty() ? "0" : resultStr;
    
    
}

int main(){
    string num1, num2;
    cin>>num1;
    cin>>num2;
    cout<<mnoz(num1, num2)<<" "<<endl;
    return 0;
}