#include <iostream>
#include <fstream>


using namespace std;

struct TrieNode {
  char letter;
  bool isEnd;
  TrieNode *children[26];

  TrieNode(char letter) {
    this->letter = letter;
    this->isEnd = false;
    for (int i = 0; i < 26; i++) {
      this->children[i] = nullptr;
    }
  }
};

TrieNode *insert(TrieNode *head, const string& word) {
  TrieNode *current = head;

  for (int i = 0; i < word.length(); i++) {
    int index = word[i] - 'a';
    if (!current->children[index]) {
      current->children[index] = new TrieNode(word[i]);
    }
    current = current->children[index];
  }
  current->isEnd = true;
  return head;
}

bool search(TrieNode *head, const string& word) {
  TrieNode *current = head;

  for (int i = 0; i < word.length(); i++) {
    int index = word[i] - 'a';

    if (!current->children[index]) {
      return false;
    }
    current = current->children[index];
  }

  if (current!=nullptr) {
    return current->isEnd;
  }else{
    return false;
  }
}

void dfs(TrieNode *head, string word) {
  if (head->isEnd) {
    cout<<word<<endl;
  }
  for (int i=0; i<26; i++) {
    if (head->children[i]) {
      dfs(head->children[i], word + head->children[i]->letter);
    }
  }
}

int main(int argc, char * argv[]) {

  ifstream inputFile;
  inputFile.open(argv[1]);

  if(!inputFile.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }

  TrieNode *head = new TrieNode('\0');

  while(!inputFile.eof()) {
    string line;
    inputFile >> line;
	insert(head, line);
  }

  inputFile.close();

  if(argc == 4 && argv[2][0] == 's'){
    if(search(head, argv[3])){
      cout<<"Słowo “"<<argv[3]<<"” występuje w słowniku"<<endl;
    }else{
      cout<<"Brak słowa “"<<argv[3]<<"” w słowniku"<<endl;
    }
  }else if (argc==3 && argv[2][2] == 'g') {
    dfs(head, "");
  }


}
