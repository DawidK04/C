#include <iostream>

using namespace std;

void showBoard(char board[3][3]);
void clearBoard(char board[3][3]);
bool isFinished(char board[3][3], char *winner);
bool setPoint(char board[3][3], unsigned int x, unsigned int y, char player);

int main() {
    char board[3][3];
    char winner = ' ';
    clearBoard(board);

    char currentPlayer = 'X';
    bool finished = false;
    int x, y;

    while (!finished) {
        showBoard(board);
        cout << "Gracz " << currentPlayer << ", podaj wspolrzedne (wiersz i kolumna, od 1 do 3): ";
        cin >> x >> y;

        if (x < 1 || x > 3 || y < 1 || y > 3) {
            cout << "Niepoprawne wspolrzedne. Sprobuj ponownie." << endl;
            continue;
        }

        if (!setPoint(board, x - 1, y - 1, currentPlayer)) {
            cout << "To pole jest już zajęte. Sprobuj ponownie." << endl;
            continue;
        }

        finished = isFinished(board, &winner);
        if (finished)
            break;

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    showBoard(board);
    if (winner == 'X' || winner == 'O')
        cout << "Gracz " << winner << " wygral!" << endl;
    else
        cout << "Remis!" << endl;

    return 0;
}

void showBoard(char board[3][3]) {
    cout << "\nAktualny stan planszy:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
    cout << endl;
}

void clearBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

bool isFinished(char board[3][3], char *winner) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            *winner = board[i][0];
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            *winner = board[0][j];
            return true;
        }
    }

    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        *winner = board[0][0];
        return true;
    }
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        *winner = board[0][2];
        return true;
    }

    bool boardFull = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                boardFull = false;
                break;
            }
        }
        if (!boardFull)
            break;
    }
    if (boardFull) {
        *winner = ' ';
        return true;
    }
    return false;
}

bool setPoint(char board[3][3], unsigned int x, unsigned int y, char player) {
    if (board[x][y] != ' ')
        return false;
    board[x][y] = player;
    return true;
}