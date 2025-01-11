#include <iostream>

using namespace std;

struct Node {

    int row;
    int col;
    Node* next;

    Node(int nRow, int nCol) {
        row = nRow;
        col = nCol;
        next = nullptr;
    }
};

bool canIPutHere(Node* head, int row, int col, int boardSize) {

    Node* temp = head;


    while (temp != nullptr) {
        if (temp->row == row && temp->col == col) {
            return false;
        }
        temp = temp->next;
    }
    return row >= 0 && row < boardSize && col >= 0 && col < boardSize;
}

bool backtracking(Node* head, int boardSize, int** chessBoard, int row, int column, int moveNumber) {

    //Potencjalne dopuszczalne ustawienia skoczka względem aktualnej pozycji
    int rowM[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int colM[] = {1, 2, 2, 1, -1, -2, -2, -1};

    //Czy ostatnie
    if (moveNumber == boardSize * boardSize + 1) {
        return true;
    }

    //Przechodzenie po wszystkich możliwościach
    for (int i = 0; i < 8; i++) {
        int probablyRow = row + rowM[i];
        int probablyCol = column + colM[i];

        if (canIPutHere(head, probablyRow, probablyCol, boardSize)) {


            chessBoard[probablyRow][probablyCol] = moveNumber;
            Node* newNode = new Node(probablyRow, probablyCol);

            newNode->next = head;
            head = newNode;

            //Przechodzenie szachownicy i sprawdzanie
            if (backtracking(head, boardSize, chessBoard, probablyRow, probablyCol, moveNumber + 1)) {
                return true;
            }

            head = head->next;
            chessBoard[probablyRow][probablyCol] = 0;
            delete newNode;
        }
    }
    return false;
}



void showBoard(int** chessBoard, int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << chessBoard[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    int boardSize = atoi(argv[1]);
    int rowPosition = atoi(argv[2]);
    int columnPosition = atoi(argv[3]);

    //Pamiętać ze dynamiczna w ten sposób
    int** chessBoard = new int*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        chessBoard[i] = new int[boardSize];
        for (int j = 0; j < boardSize; j++) {
            chessBoard[i][j] = 0;
        }
    }

    Node* head = new Node(rowPosition, columnPosition);

    //Pierwsza pozycja
    chessBoard[rowPosition][columnPosition] = 1;

    if (backtracking(head, boardSize, chessBoard, rowPosition, columnPosition, 2)) {
        showBoard(chessBoard, boardSize);
    }

    for (int i = 0; i < boardSize; i++) {
        delete[] chessBoard[i];
    }
    delete[] chessBoard;


    delete head;

    return 0;
}
