#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int potega(int wyk, float podst){
    if (wyk==0)
        {
            return 1;
        }else if(wyk==1){
            return podst;
        }else if(wyk==2){
            return podst * podst;
        }
        else{
            long int res = podst;
            for (int i = 1; i < wyk; i++)
            {
                res *= podst;
            }
            return res;
            
        }
}

float function_value(int* tab, int n, float x){
    float res = 0;
    for (int i = n; i >= 0; i--)
    {
        res += (float)tab[i] * (float)potega(n-1, x);
    }
    return res;
    
}

float szukbin(float a, float b, int* tab, int n, float tolerance = 0.001)
{ 
    float middle = (a + b) / 2; 
    float func_value_middle = function_value(tab, n, middle); 
    if (fabs(func_value_middle) <= tolerance) 
    { return middle; } 
    else if (function_value(tab, n, a) * func_value_middle < 0) { 
        return szukbin(a, middle, tab, n, tolerance); 
    } else { 
        return szukbin(middle, b, tab, n, tolerance); 
    }
}

int main(){
    int a,b, n;
    
    cout<<"a: "; cin>>a;
    cout<<"b: "; cin>>b;
    cout<<"n: "; cin>>n;

    int* tab = new int[n+1];
    int iterator = 0;
    cout<<"x"<<iterator<<": ";

    while(cin>>tab[iterator] && iterator<=n)
    {
        iterator ++;
        if(iterator<=n){
            cout<<"x"<<iterator<<": ";
        }
    }

    cout<<fixed<<setprecision(3);
    cout << "Miejsce zerowe: " << szukbin((float)a, (float)b, tab, n) << endl;

    delete [] tab;

    return 0;
}