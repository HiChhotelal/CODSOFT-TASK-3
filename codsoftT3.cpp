#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << "   1   2   3" << endl;
    cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  -----------" << endl;
    cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  -----------" << endl;
    cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

char checkWin(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return board[i][0]; 
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return board[1][1]; 
    }
    return ' '; 
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    bool playMore = true;

    while (playMore) {
        vector<vector<char>> board(3, vector<char>(3, ' ')); 
        char currentPlayer = 'X'; 

        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            cout << "Current board:" << endl;
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row column): ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move! Please try again." << endl;
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            char winner = checkWin(board);
            if (winner != ' ') {
                cout << "Player " << winner << " wins!" << endl;
                gameWon = true;
            } else if (checkDraw(board)) { 
                cout << "It's a draw!" << endl;
                gameDraw = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Final board:" << endl;
        displayBoard(board);

        playMore = playAgain();
    }

    cout << "Thank you for playing!" << endl;

    return 0;
}
