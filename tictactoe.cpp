#include <iostream>

void showBoard(char board[3][3]);
void clearBoard(char board[3][3]);
bool isFinished(char board[3][3], char *winner);
bool setPoint(char board[3][3], unsigned int x, unsigned int y, char player);

int main() {
    char board[3][3];
    char winner = ' ';
    clearBoard(board);
    char current_player = 'X';
    bool finished = false;
    int x, y;

    while(!isFinished(board, &winner)) {
        showBoard(board);
        std::cout << "Player" << current_player << "input coordinates (row and columns)";
        std::cin >> x >> y;
        if (x < 1 || x > 3 || y < 1 || y > 3) {
            std::cout << "Incorrect coordinates. Try again." << std::endl;
            continue;
        }
        if (!setPoint(board, x - 1, y - 1, current_player)) {
            std::cout << "This place is already taken. Try again." << std::endl;
            continue;
        }
        if (isFinished(board, &winner)) {
            break;
        }
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
    showBoard(board);
    if (winner == 'X' || winner == 'O') {
        std::cout << 'Player' << 'won.' << std::endl;
    }else{
        std::cout << 'Draw.' << std::endl;
    }
    return 0;
}

void showBoard(char board[3][3]) {
    std::cout << "\nCurrent state of the board:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << ' | ';
            }
            std::cout << std::endl;
            if (i < 2) {
                std::cout << '---------' << std::endl; 
            }
            std::cout << std::endl;
        }
    }
}

void clearBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

bool isFinished(char board[3][3], char *winner) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&board[i][0] == board)
    }
}