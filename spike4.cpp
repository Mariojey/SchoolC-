#include <iostream>
#include <locale>
#include <codecvt>

using namespace std;
int main() {
    int * tab = new int [10] {0,1,2,3,4,5,6,7,8,9};
    int * i = tab;
    int * end = tab + 10 - 1;
    cout<<*i<<endl;
    i++;
    cout<<*i<<endl;
    cout<<*end<<endl;
}
// "\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215 ąćęłńóśżźĄĆĘŁŃÓŚŹŻ
