//KONWERSJA

#include <iostream>

using namespace std;

string toLowerCase(string text){
    string newText = "";
    for(int i=0; i<text.length(); i++){
        int num = static_cast<int>(text[i]);
        if(num == 32){
            newText += " ";
        }else if(num >= 65 && num <= 90){
            char rep_num = static_cast<char>(num+32);
            newText += rep_num;
        }else if (num >= 97 && num <= 122){
            char rep_num = static_cast<char>(num);
            newText += rep_num;
        }
    }
    return newText;
}
string toUpperCase(string text){
    string newText = "";
    for(int i=0; i<text.length(); i++){
        int num = static_cast<int>(text[i]);
        if(num == 32){
            newText += " ";
        }else if(num >= 65 && num <= 90){
            char rep_num = static_cast<char>(num);
            newText += rep_num;
        }else if (num >= 97 && num <= 122){
            char rep_num = static_cast<char>(num-32);
            newText += rep_num;
        }
        
    }
    return newText;
}

string capitalize(string text){
    int first = static_cast<int>(text[0]);
        string newText = "";
    if (first != 32)
    {
            if (first >= 65 && first <= 90)
            {
                char rep_num = static_cast<char>(first);
                newText += rep_num;
            }else if(first >= 97 && first <= 122){
                char rep_num = static_cast<char>(first-32);
                newText += rep_num;
            }
    }
    for(int i=1; i<text.length(); i++){
        int num = static_cast<int>(text[i]);
        int num_before = static_cast<int>(text[i-1]);
        if(num_before == 32 && num != 32){
            if (num >= 65 && num <= 90)
            {
                char rep_num = static_cast<char>(num);
                newText += rep_num;
            }else if(num >= 97 && num <= 122){
                char rep_num = static_cast<char>(num-32);
                newText += rep_num;
            }
        }else{
if (num == 32)
        {
            newText += " ";
        }
        else if(num >= 65 && num <= 90){
            char rep_num = static_cast<char>(num);
            newText += rep_num;
        }else if (num >= 97 && num <= 122){
            char rep_num = static_cast<char>(num);
            newText += rep_num;
        }
        }
        
    }
    return newText;
}

int main(){
    string text;
    getline(cin, text);
    int wybor;
    cout<<"Tekst: "<<text<<endl;
    cout<<"Konwersja: "<<endl;
    cout<<"1. małe"<<endl;
    cout<<"2. WIELKIE"<<endl;
    cout<<"3. Tytułowe"<<endl;
    cin>>wybor;
    cout<<"Wybór: "<<wybor<<endl;
    switch (wybor)
        {
        case 1:
            cout<<toLowerCase(text)<<endl;
            break;

        case 2:
            cout<<toUpperCase(text)<<endl;
            break;

        case 3:
            cout<<capitalize(text)<<endl;
            break;

        default:
            break;
        }
    return 0;
}