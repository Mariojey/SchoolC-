#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Node {
    int liczba;
    Node * next;
};

void wypisz(Node * head){

    Node * w = head;

    cout<<"[";

    while (w)
    {
        cout<<setw(4);
        cout<<w->liczba;
        w = w->next;
    }

    cout<<"]";
    
}

void wypisz_odwrotnie(Node * head){
    if(head == nullptr){
        return;
    }
    wypisz_odwrotnie(head->next);
    cout<<setw(4);
    cout<<head->liczba;
}

void zamien(Node *& head, int poz1, int poz2){

    if(poz1 == poz2) return;

    Node * previous1 = nullptr;
    Node * current1 = head;

    Node * previous2 = nullptr;
    Node * current2 = head;

    for (int i = 0; current1 != nullptr && i < poz1; i++)
    {
        previous1 = current1;
        current1 = current1->next;
    }

    for (int i = 0; current2 != nullptr && i < poz2; i++)
    {
        previous1 = current2;
        current2 = current2->next;
    }

    if(current1 == nullptr || current2 == nullptr) return;

    if(previous1 != nullptr){
        previous1->next = current2;
    }else{
        head = current2;
    }

    if(previous2 != nullptr){
        previous2->next = current1;
    }else{
        head = current1;
    }

    Node * toSwap = current2->next;
    current2->next = current1->next;
    current1->next = toSwap;
    
    
}

void dodaj(Node * head, int liczba){

    Node * w = head;
    Node * newNode = new Node{liczba, nullptr};

    if(head == nullptr){
        head = newNode;
        return;
    }

    while (w->next)
    {
        w = w->next;
    }

    w->next = newNode;
    
}

void wstaw(Node * head, int liczba, int pozycja){

    Node * w = head;
    Node * newNode = new Node{liczba, nullptr};

    int iterator = 0;

    while(iterator < pozycja - 1){
        if(w==nullptr){
            return;
        }
        w = w->next;
        iterator++;
    }

    if(w==nullptr){
        return;
    }
    Node * nextElement = w->next;
    newNode->next = nextElement;
    w->next = newNode;

}

void usun(Node * head, int pozycja){
    
    Node * w = head;

    if(pozycja == 0){
        Node * element = head;
        head = head->next;
        delete element;
        return;
    }

    int iterator = 0;
    while(iterator < pozycja -1){

        if(w==nullptr){
            return;
        }
        iterator++;
        w = w->next;
    }

    if(w==nullptr||w->next==nullptr){

        return;

    }else{

        Node * nodeToDelete = w->next;
        w->next = nodeToDelete->next;
        delete nodeToDelete;
    }

}

void wyczysc(Node *& head){

    Node * w = head;

    while (w!=nullptr)
    {
        Node * nodeToSetNextNode = w->next;
        delete w;   
        w = nodeToSetNextNode;
    }

    head = nullptr;
    
}

int main(int argc, char * argv[]){

    Node * head = nullptr;

    ifstream file(argv[1]);

    while (!file.eof())
    {
        string command;
        int number1, number2;
        file>>command>>number1>>number2;
        if (command == "dodaj") 
        { 
            dodaj(head, number1); 
        } 
        else if (command == "wstaw") 
        { 
            wstaw(head, number1, number2); 
        } 
        else if (command == "usun") 
        { 
            usun(head, number1); 
        } 
        else if (command == "wyczysc") 
        { 
            wyczysc(head); 
        } 
        else if (command == "wypisz") 
        { 
            wypisz(head); 
        } 
        else if (command == "wypisz_odwrotnie") 
        { 
            wypisz_odwrotnie(head); 
        } 
        else if (command == "zamien") 
        { 
            zamien(head, number1, number2); 
        }

    }

    file.close();
    

    return 0;
}