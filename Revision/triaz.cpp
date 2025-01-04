#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

struct Node {
  string date;
  string hour;
  string pesel;
  string priorty;
  string name;
  int timespan;
  Node* next;
  Node* prev;
};

tm convertDate(const string& date, const string& hour){
  tm t{};
  istringstream ss(date + " " + hour);
  ss >> get_time(&t, "%Y-%m-%d %H:%M");
  return t;
}

void push(Node*&head, Node*newNode) {
  if (head == nullptr) {
    head = newNode;
  }else{
    Node * temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

Node* pop(Node*&head) {
  if (head == nullptr) {
    return nullptr;
  }
  Node * temp = head;
  head = head->next;
  if(head != nullptr){
    head->prev = nullptr;
  }
  return temp;
}

bool isEmpty(Node*head) {
  return head == nullptr;
}

void avgTime(Node*head, double &fullTime, int &allPatients){

  tm actualTime = convertDate(head->date, head->hour);

  while(!isEmpty(head)){

    Node * temp = pop(head);

    tm temp_time = convertDate(temp->date, temp->hour);

    time_t parsedTempTime = mktime(&temp_time);
    time_t parsedActualTime = mktime(&actualTime);

    fullTime += difftime(parsedActualTime, parsedTempTime) / 60;
    allPatients ++;

    actualTime = temp_time;
    actualTime.tm_min += temp->timespan;
  }
}

int main(int argc, char * argv[]){

  ifstream inputFile;
  inputFile.open(argv[1]);

  if(!inputFile){
    cout << "Error opening file" << endl;
    return 1;
  }

  int count_of_nodes = 0;

  Node * red = nullptr;
  Node * yellow = nullptr;
  Node * green = nullptr;

  while(!inputFile.eof()){

    string date, hour;
    string pesel, priorty, name;
    int timespan;
    inputFile >> date >> hour >> pesel >> priorty >> name >> timespan;

    Node * newNode = new Node{date, hour, pesel, priorty, name, timespan, nullptr, nullptr};

    if(priorty == "czerwony"){
      push(red, newNode);
    }else if(priorty == "żółty"){
      push(yellow, newNode);
    }else if(priorty == "zielony"){
      push(green, newNode);
    }
    count_of_nodes++;
  }

  inputFile.close();

  double fullTimeRed = 0;
  double fullTimeYellow = 0;
  double fullTimeGreen = 0;

  int allPatientsRed = 0;
  int allPatientsYellow = 0;
  int allPatientsGreen = 0;

  avgTime(red, fullTimeRed, allPatientsRed);
  avgTime(yellow, fullTimeYellow, allPatientsYellow);
  avgTime(green, fullTimeGreen, allPatientsGreen);

  double avgTimeRed = allPatientsRed > 0 ?  fullTimeRed / allPatientsRed : 0;
  double avgTimeYellow = allPatientsYellow > 0 ? fullTimeYellow / allPatientsYellow : 0;
  double avgTimeGreen = allPatientsGreen > 0 ? fullTimeGreen / allPatientsGreen : 0;

  cout<<"Priorytet czerwony: "<<fixed<<avgTimeRed<<" min."<<endl;
  cout<<"Priorytet żółty: "<<fixed<<avgTimeYellow<<" min."<<endl;
  cout<<"Priorytet zielony: "<<fixed<<avgTimeGreen<<" min."<<endl;
  return 0;
}
