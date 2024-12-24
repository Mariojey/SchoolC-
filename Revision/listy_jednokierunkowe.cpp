#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* insert(Node*& head, int data) {

  Node * ref = head;
  Node * newNode = new Node{data, nullptr};

  if (head == nullptr) {
    head = newNode;
    return head;
  }
  while (ref->next != nullptr) {
    ref = ref->next;
  }
  ref->next = newNode;
  return head;
}

Node * insert_at_pos(Node*& head, int data, int pos) {

  Node * ref = head;
  Node * newNode = new Node{data, nullptr};

  if (pos == 0) {
    Node * afterHead = head;
    head = newNode;
    head->next = afterHead;
    return head;
  }

  int iterator = 0;

  while (iterator < pos - 1) {
    if(ref==nullptr){
      break;
    }
    ref = ref->next;
    iterator++;
  }

  if(ref==nullptr){
    return head;
  }

  Node * temp = ref->next;
  newNode->next = temp;
  ref->next = newNode;
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
  ref->next = temp->next;
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

void display(Node* head) {
  Node * ref = head;
  cout<<"[";
  while (ref != nullptr) {
    cout << setw(4) << ref->data << " ";
    ref = ref->next;
  }
  cout<<"]"<<endl;
}

void reverseDisplay(Node* head) {
   if (head == nullptr)
     return;
   reverseDisplay(head->next);
   cout << setw(4) << head->data << " ";
}

void swap(Node *& head, int pos1, int pos2) {

  if (pos1 == pos2) return ;

  Node * prev1 = nullptr;
  Node *curr1 = head;

  Node * prev2 = nullptr;
  Node * curr2 = head;

  for(int i = 0; curr1 != nullptr && i < pos1; i++) {
    prev1 = curr1;
    curr1 = curr1->next;
  }

  for(int i = 0; curr2 != nullptr && i < pos2; i++) {
    prev2 = curr2;
    curr2 = curr2->next;
  }

  if(prev1 == nullptr && curr2 == nullptr) return ;

  if(prev1 != nullptr) prev1->next = curr2;
  else head = curr2;

  if(prev2 != nullptr) prev2->next = curr1;
  else head = curr1;

  Node * toSwap = curr2->next;
  curr2->next = curr1->next;
  curr1->next = toSwap;

}

int main(int argc, char *argv[]) {

  ifstream file;
  file.open(argv[1]);

  if (!file) {
    cout << "File could not be opened" << endl;
    return 1;
  }

  Node* head = nullptr;

  while (!file.eof()) {
    string command;
    file>>command;

    if (command == "dodaj"){
      int value;
      file>>value;
      insert(head, value);
    }
    else if (command == "wstaw"){
      int value, position;
      file>>value>>position;
      insert_at_pos(head, value, position);
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