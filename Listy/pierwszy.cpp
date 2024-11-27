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

int main(int argc, char * argv[]){

    // ifstream file(argv[1]);

    Node * first = new Node{1, nullptr};
    Node * second = new Node{2, nullptr};

    Node * head = first;
    head->next = second;

    dodaj(head, 3);
    wypisz(head);

    return 0;
}