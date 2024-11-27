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

    // ifstream file(argv[1]);

    Node * first = new Node{1, nullptr};
    Node * second = new Node{2, nullptr};

    Node * head = first;
    head->next = second;

    dodaj(head, 4);
    wstaw(head, 3,2);
    wypisz(head);
    usun(head, 2);
    wypisz(head);

    return 0;
}