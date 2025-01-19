#include <iostream>

using namespace std;

int diff = 'a' - 'A';
string HighPolishLetter = u8"ĄĘĆŻŹÓŃŁŚ";
string LowPolishLetter = u8"ąęćżźóńłś";

void toLowerCase(string &str, int & i){

  u_char character = static_cast<u_char>(str[i]);

  if(character >= 'A' && character <= 'Z'){
    str[i] = character - diff;
  }
  else if((character >> 5) == 0b110){
    for(int iter = 0; iter<HighPolishLetter.length(); iter+=2){


      //Te polskie znaki zapisują sie na dwóch bajtach ---zapamiętać
      if(
          str[i] == HighPolishLetter[iter]
      ){
        if(str[i+1] == HighPolishLetter[iter+1]){
          str[i+1] = HighPolishLetter[iter+1];
          break;
        }
      }
    }
    i++;
  }
}

void toUpperCase(string &str, int & i){

  u_char character = static_cast<u_char>(str[i]);

  if(character >= 'a' && character <= 'z'){
    str[i] = character - diff;
  }else if((character >> 5) == 0b110){
    for(int iter = 0; iter<LowPolishLetter.length(); iter+=2){
      if(str[i] == LowPolishLetter[iter]){
        if(str[i+1] == LowPolishLetter[iter+1]){
          str[i+1] = LowPolishLetter[iter+1];
          break;
        }
      }
    }
    i++;
  }



}


int main() {
  string input;
  cout<<"tekst: ";
  getline(cin, input);
  int inputLength = input.length();

  cout<< "Konwersja: "<<endl;
  cout<< "1. małe"<<endl;
  cout<< "2. WIELKIE"<<endl;
  cout<< "3. Tytułowe"<<endl;
  cout<<"Wybór: ";

  int userInput;
  cin>>userInput;

  if(userInput == 1){
    for(int i = 0; i < inputLength; i++){
      toLowerCase(input, i);
    }
  }
  else if(userInput == 2){
    for(int i = 0; i < inputLength; i++){
      toUpperCase(input, i);
    }
  }
  else if(userInput == 3){
    bool isFirstCharacter = true;
    for(int i = 0; i < inputLength; i++){
      if(isFirstCharacter){
        toUpperCase(input, i);
      }else{
        toLowerCase(input, i);
      }
      if(input[i] == ' '){
        isFirstCharacter = true;
      }else{
        isFirstCharacter = false;
      }
    }
  }
  cout<<input;
  return 0;
}
