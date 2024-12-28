#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Node{
  int data;
  Node* next;
  Node* prev;
};

Node * addNode(Node * & head, int data){

  Node * newNode = new Node{data, nullptr, nullptr};

  if(head == nullptr){
    head = newNode;
    return head;
  }

  while(head->next != nullptr){
    head = head->next;
  }
  head->next = newNode;
  newNode->prev = head;
  return newNode;

}

Node * insert(Node * & head, int data, int index){

  Node * newNode = new Node{data, nullptr, nullptr};

  if(index == 0){
    newNode->next = head;
    if(head == nullptr){
      head->prev = newNode;
    }
    head = newNode;
    return head;
  }

  Node * current = head;
  int i = 0;
  while(current->next != nullptr && i < index - 1){
    current = current->next;
    i++;
  }

  //Jeżeli index jest poza zakresem
  if(current == nullptr){
    delete newNode;;
    return nullptr;
  }

  Node * nextNode = current->next;
  newNode->next = nextNode;
  nextNode->prev = current;
  current->next = newNode;

  if(nextNode != nullptr){
    nextNode->prev = newNode;
  }

  return head;
}

Node * deleteNode(Node*& head, int pos) {
  Node * ref = head;
  int iterator = 0;
  while (iterator < pos - 1) {
    ref = ref->next;
    iterator++;
  }
  Node * temp = ref->next;
  Node * next = temp->next;
  ref->next = next;
  next->prev = ref;
  delete temp;
  return head;
}

Node * clear(Node*& head) {
  Node * ref = head;
  while (ref != nullptr) {
    Node * temp = ref->next; //Set next node as current
    delete ref; //And delete previous current
    ref = temp;
  }
  head = nullptr;
  return head;
}

void display(Node*& head) {
  Node * ref = head;
  cout<<"[";
  while (ref != nullptr) {
    cout << setw(4) << ref->data << " ";
    ref = ref->next;
  }
  cout<<"]"<<endl;
}

void reverseDisplay(Node* head) {
  while(head->next != nullptr){
    head = head->next;
  }
  while(head != nullptr){
    cout << setw(4) << head->data << " ";
    head = head->prev;
  }
}


void swap(Node*&head, int pos1, int pos2) {

  if (pos1 == pos2) return;

  Node * prev1 = nullptr;
  Node * curr1 = head;
  Node * prev2 = nullptr;
  Node * curr2 = head;

  for (int i = 0; curr1 != nullptr && i < pos1; i++) {
    prev1 = curr1;
    curr1 = curr1->next;
  }

  for (int i=0; curr2 != nullptr && i < pos2; i++) {
    prev2 = curr2;
    curr2 = curr2->next;
  }

  if (curr1 == nullptr || curr2 == nullptr) return ;

  if (prev1 != nullptr) {
    prev1->next = curr2;
  }else {
    head = curr2;
  }

  if (prev2 != nullptr) {
    prev2->next = curr1;
  }else {
    head = curr1;
  }

  Node * temp = curr1->next;
  curr1->next = curr2->next;
  curr2->next = temp;

  if (curr1->next != nullptr) {
    curr1->next->prev = curr1;
  }
  if (curr2->next != nullptr) {
    curr2->next->prev = curr2;
  }

  temp = curr1->prev;
  curr1->prev = curr2->prev;
  curr2->prev = temp;

  if (curr1->prev != nullptr) {
    curr1->prev->next = curr1;
  }
  if (curr2->prev != nullptr) {
    curr2->prev->next = curr2;
  }
}

int main(int argc, char *argv[]) {
  fstream file;
  file.open(argv[1]);

  if (!file.is_open()) {
    cout << "Nie można otworzyć pliku" << endl;
    return 1;
  }

  Node * head = nullptr;

  while (!file.eof()) {
    string command;
    file >> command;
    if (command == "dodaj"){
      int value;
      file>>value;
      addNode(head, value);
    }
    else if (command == "wstaw"){
      int value, position;
      file>>value>>position;
      insert(head, value, position);
    }
    else if (command == "usun"){
      int position;
      file>>position;
      deleteNode(head, position);
    }
    else if (command == "wyczysc"){
      clear(head);
    }
    else if (command == "wypisz"){
      display(head);
    }
    else if (command == "wypisz_odwrotnie"){
      cout<<"[";
      reverseDisplay(head);
      cout<<"]"<<endl;
    }
    else if (command == "zamien"){
      int position1, position2;
      file>>position1>>position2;
      swap(head, position1, position2);
    }
  }
  return 0;
}