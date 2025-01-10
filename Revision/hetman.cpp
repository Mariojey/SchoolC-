#include <iostream>

using namespace std;

const int maxBoardSize = 16;
char chessBoard[maxBoardSize][maxBoardSize]; //Reminder! Tylko stałe mogą być używane jako rozmiar tablicy

int hashes[maxBoardSize][maxBoardSize]; // tablica do tych # na wyjściu

struct Node {
    int row;
    int col;
    Node *next;

    Node(int nRow, int nCol) {
        row = nRow;
        col = nCol;
        next = nullptr;
    }
};

bool canIPutHere(Node *head, int row, int col, int boardSize) {
    Node *temp = head;

    while (temp != nullptr) {
        if (temp->col == col || temp->row - temp->col == row - col || temp->row + temp->col == row + col) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void hashOnBoard(Node *head, int boardSize, int value) {
    Node *temp = head;
    while (temp != nullptr) {
        int row = temp->row;
        int col = temp->col;

        for (int i = 0; i < boardSize; i++) {
            hashes[row][i] += value;
            hashes[i][col] += value;

            // SPrawdzenie czy trzeba dać ##
            if (row + i < boardSize && col + i < boardSize) {
                hashes[row + i][col + i] += value;
            }

            if (row - i >= 0 && col - i >= 0) {
                hashes[row - i][col - i] += value;
            }

            if (row - i >= 0 && col + i < boardSize) {
                hashes[row - i][col + i] += value;
            }

            if (row + i < boardSize && col - i >= 0) {
                hashes[row + i][col - i] += value;
            }
        }
        temp = temp->next;
    }
}

void showBoard(Node *head, int boardSize) {
    // Inicjalizaco-wypełnienie spacjami
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            chessBoard[i][j] = ' ';
        }
    }

    Node *temp = head;

    while (temp != nullptr) {
        chessBoard[temp->row][temp->col] = 'X'; // Tutaj stoi hetman
        temp = temp->next;
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (chessBoard[i][j] == 'X') {
                cout << "[]";
            } else if (hashes[i][j] >= 2) {
                cout << "##";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void backtracking(int row, int boardSize, Node *head, int boardsToDisplay) {
    if (row == boardSize) {
        boardsToDisplay++;
        showBoard(head, boardSize);
        return;
    }

    // Przechodzenie szachownicy
    for (int columnIndex = 0; columnIndex < boardSize; ++columnIndex) {
        if (canIPutHere(head, row, columnIndex, boardSize)) {
            Node *newNode = new Node(row, columnIndex);
            newNode->next = head;

            hashOnBoard(newNode, boardSize, 1);
            backtracking(row + 1, boardSize, newNode, boardsToDisplay);
            hashOnBoard(newNode, boardSize, -1);

            delete newNode;
        }
    }
}

void getTables(int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            hashes[i][j] = 0;
        }
    }
}

int main() {
    int boardSize;
    cin >> boardSize;

    getTables(boardSize);
    int boardsToDisplay = 0;

    Node * head = nullptr;
    backtracking(0, boardSize, head, boardsToDisplay);

    return 0;
}
