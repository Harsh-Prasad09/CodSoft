#include <iostream>
using namespace std;

void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}


bool checkWin(char board[3][3], char player_input) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player_input && board[i][1] == player_input && board[i][2] == player_input)
            return true;
        if (board[0][i] == player_input && board[1][i] == player_input && board[2][i] == player_input)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player_input && board[1][1] == player_input && board[2][2] == player_input)
        return true;
    if (board[0][2] == player_input && board[1][1] == player_input && board[2][0] == player_input)
        return true;
    return false;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char currentPlayer = 'X';
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (true) {
        drawBoard(board);
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Thanks for playing!\n";
    return 0;
}
