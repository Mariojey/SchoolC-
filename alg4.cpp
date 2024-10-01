#include <iostream>

using namespace std;

int main(){
    string text;
    getline(cin, text);
    string vanillaText = text;
int i = 0;
int indicator_in_text = 0;
int cout_of_spaces = 0;
string new_text;
while(i<vanillaText.length()){
    if(i>=(vanillaText.length()-cout_of_spaces)){
        i++;
    }else{
    if(static_cast<int>(text[indicator_in_text]) == 32){
        cout_of_spaces ++;
    }else if(static_cast<int>(text[indicator_in_text]) >= 65 && static_cast<int>(text[indicator_in_text]) <= 90){
        new_text += static_cast<char>(static_cast<int>(text[indicator_in_text])+32);
        i++;
    }else if(static_cast<int>(text[indicator_in_text]) >= 97 && static_cast<int>(text[indicator_in_text]) <= 122){
        new_text += text[indicator_in_text];
        i++;}
    indicator_in_text ++;
    }

}

bool isPali = true;
for (int j = 0; j<new_text.length()/2; j++ ){
    if(new_text[j] != new_text[new_text.length()-1-j]){
        isPali = false;
    }
}
if(isPali == true){
    cout<<"Ci¹g znaków: "<<vanillaText<<endl;
        cout<<"Ci¹g \""<<vanillaText<<"\" jest palindromem."<<endl;
}else{
    cout<<"Ci¹g znaków: "<<vanillaText<<endl;
        cout<<"Ci¹g \""<<vanillaText<<"\" nie jest palindromem."<<endl;
}
    return 0;
}
