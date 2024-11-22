#include <iostream>
#include <time.h>

using namespace std;

unsigned long long fibonacci_rek(int n){
    if (n==1|n==2)
    {
        return 1;
    }
    return fibonacci_rek(n-2) + fibonacci_rek(n-1);
    
}

int main(){
    for (int i = 1; i <= 50; i++)
    {
        time_t start = time();
        int value = fibonacci_rek(i);
        time_t stop = time();
        
    }
    
    
}