#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

struct TrieNode{
  char letter;
  bool isEnd;
  TrieNode *left, *right;

  TrieNode(char letter){
    this->letter = letter;
    this->isEnd = false;
    this->left = nullptr;
    this->right = nullptr;
  }
};

TrieNode* readLine(istringstream &iss){
  //Przekształcenie tekstu z pliku na znaki możliwe do zapisania jako liście
  char character;
  if(!(iss >> character)){
    return nullptr;
  }

  while(isspace(character)){
    iss >> character; //Ignorowanie
  }

  if(character == '('){

    iss >> character;

    TrieNode *temp = new TrieNode(character);

    temp->left = readLine(iss);
    temp->right = readLine(iss);

    iss >> character; //Zamknięcie wyrażenia
    return temp;
  }else{ // Jeżeli wyrażenie jest jednym znakiem
    return new TrieNode(character);
  }
}

//Funkcje do przechodzenia drzewa
void preOrder(TrieNode *head){
  if(head == nullptr){
    return;
  }
  cout << head->letter<<" ";
  preOrder(head->left);
  preOrder(head->right);
}

void inOrder(TrieNode *head, bool isBracketUseless){

  if(head == nullptr){
    return;
  }

  if (!isBracketUseless) {
    cout<<"(";
  }

  inOrder(head->left, false);
  cout << head->letter<<" ";
  inOrder(head->right, false);

  if(!isBracketUseless) {
    cout<<")";
  }
}

void postOrder(TrieNode *head){
  if(head == nullptr){
    return;
  }
  postOrder(head->left);
  postOrder(head->right);
  cout << head->letter<<" ";
}

int main(int argc, char * argv[]){

  ifstream inputFile;
  inputFile.open(argv[1]);

  if(!inputFile.is_open()){
    cout<<"Nie ma takiego pliku"<<endl;
    return 1;
  }

  string line;
  getline(inputFile, line);
  inputFile.close();

  //Usuwanie białych znaków z tekst
  line.erase(remove(line.begin(), line.end(), ' '), line.end());
  line.erase(remove(line.begin(), line.end(), ','), line.end());

  istringstream iss(line);

  TrieNode * head = readLine(iss); // Zbudowanie drzewa

  //Wypisanie wartości
  cout<<"Wyrażenie: "<<line<<endl;
  cout<<"In-order - notacja wrostkowa"<<endl;
  inOrder(head, true);
  cout<<endl;
  cout<<"Pre-order - notacja polska"<<endl;
  preOrder(head);
  cout<<endl;
  cout<<"Post-order - odwrotna notacja polska"<<endl;
  postOrder(head);
  cout<<endl;

  return 0;
}
