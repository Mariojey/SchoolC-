#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Node{
  string date;
  string name;
  string pesel;
  Node * nextByAlphabet;
  Node * nextByAge;
  Node * nextByVisitDate;
};

void insertInSortedNodes(Node * newNode, Node * &head, bool orderByAlphabet, bool orderByAge, bool orderByVisitDate){
  if(orderByAlphabet){
    if(!head || newNode->name < head->name){
      newNode->nextByAlphabet = head;
      head = newNode;
    }else{
      Node * currentNode = head;
      while(currentNode->nextByAlphabet && !(newNode->name < currentNode->nextByAlphabet->name)){
        currentNode = currentNode->nextByAlphabet;
      }
      newNode->nextByAlphabet = currentNode->nextByAlphabet;
      currentNode->nextByAlphabet = newNode;
    }
  }else if(orderByAge){
    if(!head || newNode->pesel < head->pesel){
      newNode->nextByAge = head;
      head = newNode;
    }else{
      Node * currentNode = head;
      while(currentNode->nextByAge && !(newNode->pesel < currentNode->nextByAge->pesel)){
        currentNode = currentNode->nextByAge;
      }
      newNode->nextByAge = currentNode->nextByAge;
      currentNode->nextByAge = newNode;
    }
  }else if(orderByVisitDate){
    if(!head || newNode->date < head->date){
      newNode->nextByVisitDate = head;
      head = newNode;
    }else{
      Node * currentNode = head;
      while(currentNode->nextByVisitDate && !(newNode->date < currentNode->nextByVisitDate->date)){
        currentNode = currentNode->nextByVisitDate;
      }
      newNode->nextByVisitDate = currentNode->nextByVisitDate;
      currentNode->nextByVisitDate = newNode;
    }
  }
}

void addPatient(const string &date, const string& pesel, const string &name, Node *& headByAlphabet, Node *& headByAge, Node *& headByVisitDate){
  Node * newNode = new Node{date, pesel, name, nullptr, nullptr, nullptr};
  insertInSortedNodes(newNode, headByAlphabet, true, false, false);
  insertInSortedNodes(newNode, headByAge, true, true, false);
  insertInSortedNodes(newNode, headByVisitDate, true, false, true);
}

void removeNode(Node * & head, const string&date, const string&orderBy){
  if(orderBy == "alphabet"){
    Node * currentNode = head;
    Node * prev = nullptr;
    while(currentNode){
      if(currentNode->date == date){
        if(prev){
          prev->nextByAlphabet = currentNode->nextByAlphabet;
        }else{
          head = currentNode->nextByAlphabet;
        }
        delete currentNode;
        return;
      }
      prev = currentNode;
      currentNode = currentNode->nextByAlphabet;
    }
  }else if(orderBy == "age"){
    Node * currentNode = head;
    Node * prev = nullptr;
    while(currentNode){
      if(currentNode->date == date){
        if(prev){
          prev->nextByAge = currentNode->nextByAge;
        }else{
          head = currentNode->nextByAge;
        }
        delete currentNode;
        return;
      }
      prev = currentNode;
      currentNode = currentNode->nextByAge;
    }
  }else if(orderBy == "visitDate"){
    Node * currentNode = head;
    Node * prev = nullptr;
    while(currentNode){
      if(currentNode->date == date){
        if(prev){
          prev->nextByVisitDate = currentNode->nextByVisitDate;
        }else{
          head = currentNode->nextByVisitDate;
        }
        delete currentNode;
        return;
      }
      prev = currentNode;
      currentNode = currentNode->nextByVisitDate;
    }
  }
}

void removeVisit(string&date, Node * &headByAlphabet, Node * &headByAge, Node * &headByVisitDate){
  removeNode(headByAlphabet, date, "alphabet");
  removeNode(headByAge, date, "age");
  removeNode(headByVisitDate, date, "visitDate");
}

void printList(Node * head, const string&orderBy){
  if(orderBy == "alphabet"){
    Node * currentNode = head;
    while(currentNode){
      cout << currentNode->date << " " << currentNode->name << " " << currentNode->pesel << endl;
      currentNode = currentNode->nextByAlphabet;
    }
  }else if(orderBy == "age"){
    Node * currentNode = head;
    while(currentNode){
      cout << currentNode->date << " " << currentNode->name << " " << currentNode->pesel << endl;
      currentNode = currentNode->nextByAge;
    }
  }else if(orderBy == "visitDate"){
    Node * currentNode = head;
    while(currentNode){
      cout << currentNode->date << " " << currentNode->name << " " << currentNode->pesel << endl;
      currentNode = currentNode->nextByVisitDate;
    }
  }
}

void printAlphabet(Node *& headByAlphabet){
  printList(headByAlphabet, "alphabet");
}

void printAge(Node *& headByAge){
  printList(headByAge, "alphabet");
}

void printVisit(Node *& headByVisitDate){
  printList(headByVisitDate, "alphabet");
}

int main(int argc, char * argv[]) {

  ifstream inputFile;
  inputFile.open(argv[1]);

  if (!inputFile.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }

  Node * headByAlphabet = nullptr;
  Node * headByAge = nullptr;
  Node * headByVisitDate = nullptr;

  string line;
  while (getline(inputFile, line)) {
    istringstream iss(line);
    string command;
    iss >> command;
    cout << command << endl;
    if (command == "dodaj") {
      string date, pesel, name;
      iss>>date>>pesel;
      getline(iss, name);
      addPatient(date, pesel, name, headByAlphabet, headByAge, headByVisitDate);
    }else if(command == "usun"){
      string date;
      iss >> date;
      removeVisit(date, headByAlphabet, headByAge, headByVisitDate);
    }else if(command == "wypisz"){
      string date;
      iss >> date;
      if(date == "alfabetycznie"){
        printAlphabet(headByAlphabet);
      }else if(date == "wiekiem"){
        printAge(headByAge);
      }else if(date == "wizytami"){
        printVisit(headByVisitDate);
      }
    }
  }

  inputFile.close();
  return 0;
}