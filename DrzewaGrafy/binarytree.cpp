#include <iostream>

using namespace std;

struct Node
{
    int number;
    Node * left;
    Node * right;
};

//Tworzenie nowego węzła

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->number = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

//Dodawanie nowego węzła do korzenia

Node* insert(Node*root, int value){

    Node*newNode = createNode(value);

    if (root == nullptr)
    {
        return newNode;
    }else{
        if (root->number > value)
        {
            root->left = newNode;
        }else if(root->number < value){
            root->right = newNode;
        }
    }
    return root;
}

//Funkcja do wyszukiwania podanego węzła w drzewie

bool search(Node*root, int value){
    if (root == nullptr)
    {
        return false;
    }

    if(value == root->number){
        return true;
    }else if (value < root->number)
    {
        return search(root->left, value);
    }else if (value > root->number){
        return search(root->right, value);
    }
    
}

Node * minimum(Node*root){
  Node*current = root;
  while(current && current->left != nullptr){
    current = current->left;
  }
  return current;
}

//Usuwanie węzła w drzewie

Node* remove(Node * root, int value){

    if (root==nullptr)
    {
        return root;
    }

    if(value < root->number){
        root->left = remove(root->left, value);
    }else if(value > root->number){
        root->right = remove(root->right, value);
    }else{
        if(root->left == nullptr ){
            Node * temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            Node * temp = root->left;
            delete root;
            return temp;

        }
        Node * temp = minimum(root->right);
        root->number = temp->number;
        root->right = remove(root->right, temp->number);
    }
    return root;
}

int main(){

    return 0;
}