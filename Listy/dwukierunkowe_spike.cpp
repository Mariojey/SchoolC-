#include <iostream>

using namespace std;

struct Node
{
    int liczba;
    Node * next;
    Node * prev;
};


int main(){
    Node * first = new Node{0, nullptr, nullptr};
    Node * second = new Node{1, nullptr,first};
    first->next = second;
    Node * w = first;
    while (w)
    {
        cout<<w->liczba;
        w = w->next;
    }
    
    return 0;
}