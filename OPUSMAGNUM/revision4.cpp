#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string num1, num2;
    cin>>num1;
    cin>>num2;
    cout<<endl;

    int num1_len = num1.size();
    int num2_len = num1.size();

    vector<int>res(num1_len + num2_len, 0);

    for (int i = num1_len-1; i >= 0; i--)
    {
        for (int j = num2_len-1; j >=  0; j--)
        {
            int multipl = (num1[i] - '0') * (num2[j] - '0');
            int sum = multipl + res[i + j + 1];
            res[i+j+1] = sum % 10;
            res[i+j] = sum / 10;
        }
        
    }
    string resultStr = "";
    for (int k = 0; k < num1_len+num2_len; k++)
    {
        if (!(resultStr.empty() && res[k] == 0))
        {
            resultStr.push_back(res[k] + '0');
        }
        
    }
    cout<<resultStr;

    return 0;
}