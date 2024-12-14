#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node{

    char letter;
    bool isEndOfWord;

    vector<Node*> children;

    Node(char used_letter) : letter(used_letter), isEndOfWord(false) {} 
};

//Tworzenie nowego węzła

Node * createNode(char letter){
    Node* newNode = new Node(letter);
    return newNode;
}

//Dodawanie słowa do drzewa
void insertWord(Node* head, const string& word){
    
    Node*current = head;

    for(char character: word){

        bool isExists  = false;
        //Czy węzeł już istnieje
        for(Node* child: current->children){

            if(child->letter == character){
                current = child;
                isExists = true;
                break;
            }
        }

        //Jeżeli nie istnieje
        if(!isExists){
            Node* newNode = new Node(character);
            current->children.push_back(newNode);
            current = newNode;
        }

    }

    //I na koniec oznaczamy koniec słowa
    current->isEndOfWord = true; 
}

//Sprawdzanie czy słowo znajduje się w słowniku
bool searchWord(Node* head, const string& word){
    Node* current = head;
    for(char character: word){

        bool isExist = false;

        for(Node * child: current->children){
            if(child->letter = character){
                current = child;
                isExist = true;
                break;
            }
        }

        if(!isExist){
            return false;
        }

        return current->isEndOfWord;
    }
}

int main(int argc, char*argv[]){

    ifstream file(argv[1]);
    Node * head = nullptr;

    if (!file)
    {
        cout<<"Nie udało sie poprawnie odczytać danych z pliku"<<endl;
        file.close();
    }else{
        string line;
        while(getline(file,line)){
            insertWord(head, line);
        }
        file.close();
    }

    if(argc == 4){
        bool isExist = searchWord(head, argv[4]);
        
        if(isExist) cout<<"Słowo \""<<argv[4]<<"\" występuje w słowniku";
        else cout<<"Brak słowa \""<<argv[4]<<"\" w słowniku";
    }
    

    return 0;
}