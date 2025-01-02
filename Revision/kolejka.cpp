#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Node{
  string name;
  string surname;
  int age;
  float weight;
  Node* next;
};

string centered(int width, const string& str) {
  int len = str.length();
  if(width < len) { return str; }

  int diff = width - len;
  int pad1 = diff/2;
  int pad2 = diff - pad1;
  return string(pad1, ' ') + str + string(pad2, ' ');
}

Node * insert(Node* &head, string name, string surname, int age, float weight){

  Node* temp = new Node;

  temp->name = name;
  temp->surname = surname;
  temp->age = age;
  temp->weight = weight;
  temp->next = nullptr;

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

void deleteFirstElement(Node* &head){
  if(head == nullptr){
    cout<<"Kolejka jest pusta, nie można pobrać elementu."<<endl;
  }
  Node *p = head;
  head = head->next;
  delete p;
  return;
}

void display(Node* head){

  if(head == nullptr){
    cout<<"Kolejka jest pusta."<<endl;
    return;
  }

  Node *p = head;
  int iterator = 1;

  cout<<setw(3) << centered(3,"NR");
  cout<<"|";
  cout<<setw(25) << centered(25,"IMIE");
  cout<<"|";
  cout<<setw(25) << centered(25,"NAZWISKO");
  cout<<"|";
  cout<<setw(4) << centered(4,"WIEK");
  cout<<"|";
  cout<<setw(5) << centered(5,"WAGA");
  cout<<endl;

  while(p != nullptr){
    cout<<setw(3) << iterator;
    cout<<"|";
    cout<<setw(25) << p->name;
    cout<<"|";
    cout<<setw(25) << p->surname;
    cout<<"|";
    cout<<setw(4) << p->age;
    cout<<"|";
    cout<<setw(5) << p->weight;
    iterator++;
    cout<<endl;
    p = p->next;
  }

}

void size(Node* head){
  if(head == nullptr){
    cout<<"Kolejka jest pusta."<<endl;

    return;
  }
  int size = 0;
  Node *p = head;
  while(p->next != nullptr){
    p = p->next;
    size++;
  }
  size++;
  cout<<"Rozmiar kolejki: "<<size<<endl;
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
    if(command == "zakolejkuj"){
      string name, surname;
      int age;
      float weight;
      file>>name>>surname>>age>>weight;
      insert(head, name, surname, age, weight);
    }else if(command == "pobierz"){
      deleteFirstElement(head);
    }else if(command == "wypisz"){
      display(head);
    }else if(command == "rozmiar"){
      size(head);
    }
  }
}
