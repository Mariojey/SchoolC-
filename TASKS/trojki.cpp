#include <iostream>

using namespace std;

int main(){
    int n=0;
    cin>>n;
    for (int c = 1; c < n; c++)
    {
        for (int b = 1; b < n; b++)
        {
            for (int a = 1; a < n; a++)
            {
                if ((a*a + b*b) == (c*c))
                {
                    cout<<a<<" "<<b<<" "<<c<<endl;
                }
                
            }
            
        }
        
    }
    

    return 0;
}