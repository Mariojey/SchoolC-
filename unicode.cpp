#include <iostream>

using namespace std;

int main(){
    string domyslne = "ŚIĄŚĆ";
    wstring utf8 = "ŚIĄŚĆ";
    u16string utf16 = u"ŚIĄŚĆ";
    u32string utf32 = U"ŚIĄŚĆ";

    wcout<<utf8<<endl;
    return 0;
}