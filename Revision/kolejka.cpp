#include <iostream>
#include <fstream>

using namespace std;

struct Node{
  string name;
  string surname;
  int age;
  int weight;
  Node* next;
};

Node * insert(Node* &head, string name, string surname, int age, int weight){

  Node* temp = new Node;

  temp->name = name;
  temp->surname = surname;
  temp->age = age;
  temp->weight = weight;

  if(head == nullptr){
    head = temp;
    return head;
  }

  Node *p = head;
  while(p->next != nullptr){
    p = p->next;
  }
  p->next = temp;
  return head;
}

int main(int argc, char * argv[]){

  ifstream file;
  file.open(argv[1]);
  if (!file){
    cerr << "Error opening file " << argv[1] << endl;
    return 1;
  }

  Node * head = nullptr;

  while(!file.eof()){
    string command;
    file>>command;
  }
}
