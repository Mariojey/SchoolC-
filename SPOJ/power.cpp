#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    cin>>ws;
    int * powered = new int[n];
    for(int i=0; i<n; i++){
        string line;
        getline(cin, line);
        int a = line[0] - '0';
        int b = line[2] - '0';
        if (b==0)
        {
            powered[i] = 1;
        }
        if (b==1)
        {
            powered[i] = a;
        }
        if(b>1){
            int sup = a;
        for(int j=2; j<=b; j++){
            a = a*sup;
        }powered[i] = a;
        }
    }
    for(int i=0; i<n; i++){
        while ((powered[i]/10)>=10)
        {
            powered[i] = powered[i]/10;
        }
        cout<<powered[i]%10<<endl;
    }
}