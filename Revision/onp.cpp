#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Node {
    char character;
    Node* next;
};

Node* createNode(char letter) {
    Node* newNode = new Node{letter, nullptr};
    return newNode;
}

Node* pushNewElement(Node*& head, char letter) {
    Node* newNode = createNode(letter);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    return newNode;
}

char top(Node* head) {
    if (head == nullptr) {
        return ' ';
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current->character;
}

char pop(Node*& head) {
    if (head == nullptr) {
        return ' ';
    }
    if (head->next == nullptr) {
        char value = head->character;
        delete head;
        head = nullptr;
        return value;
    }
    Node* prev = head;
    Node* curr = head->next;
    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    char value = curr->character;
    prev->next = nullptr;
    delete curr;
    return value;
}

bool isEmpty(Node* head) {
    return head == nullptr;
}

bool isOperator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/';
}

int getPriority(char character) {
    switch (character) {
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

string infixToONP(const string& infix) {
    Node* stack = nullptr;
    string output = "";

    for (char element : infix) {
        if (isspace(element)) {
            continue;  // Ignoruj spacje
        } else if (isdigit(element)) {
            output += element;
            output += ' ';  // Dodaj spację po każdej cyfrze
        } else if (isOperator(element)) {
            while (!isEmpty(stack) && getPriority(top(stack)) >= getPriority(element)) {
                output += pop(stack);
                output += ' ';  // Dodaj spację po operatorze
            }
            pushNewElement(stack, element);
        } else if (element == '(') {
            pushNewElement(stack, element);
        } else if (element == ')') {
            while (!isEmpty(stack) && top(stack) != '(') {
                output += pop(stack);
                output += ' ';  // Dodaj spację po operatorze
            }
            if (!isEmpty(stack)) {
                pop(stack);
            }
        }
    }

    while (!isEmpty(stack)) {
        output += pop(stack);
        output += ' ';  // Dodaj spację po operatorze
    }

    return output;
}

int evaluateONP(const string& onp) {
    Node* stack = nullptr;
    string number = "";

    for (char element : onp) {
        if (isspace(element)) {
            if (!number.empty()) {
                pushNewElement(stack, stoi(number));
                number.clear();
            }
        } else if (isdigit(element)) {
            number += element;
        } else if (isOperator(element)) {
            if (!number.empty()) {
                pushNewElement(stack, stoi(number));
                number.clear();
            }
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result;
            switch (element) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            pushNewElement(stack, result);
        }
    }

    return pop(stack);
}

int main() {
    string infix;
    cout << "Wyrażenie: ";
    getline(cin, infix);
    string onp = infixToONP(infix);
    cout << endl;
    cout << "ONP: " << onp << endl;
    int result = evaluateONP(onp);
    cout << "Wynik: " << result << endl;
    return 0;
}
