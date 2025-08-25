#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, 
                     {'4','5','6'}, 
                     {'7','8','9'} };

char current_marker;
int current_player;

// Function to draw the board
void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

// Function to place a marker on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = current_marker;
    return true;
}

// Function to check if someone has won
int checkWinner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

// Function to swap player turns
void swapPlayerAndMarker() {
    if (current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if (current_player == 1) current_player = 2;
    else current_player = 1;
}

int main() {
    cout << "Tic-Tac-Toe Game\n";
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    drawBoard();

    int player_won = 0;
    for (int i = 0; i < 9; i++) {
        cout << "Player " << current_player << ", enter your slot (1-9): ";
        int slot;
        cin >> slot;

        if (!placeMarker(slot)) {
            cout << "Invalid move! Try again.\n";
            i--; // redo the turn
            continue;
        }

        drawBoard();
        player_won = checkWinner();

        if (player_won == 1) { cout << "Player 1 wins!\n"; break; }
        if (player_won == 2) { cout << "Player 2 wins!\n"; break; }

        swapPlayerAndMarker();
    }

    if (player_won == 0) {
        cout << "It's a draw!\n";
    }

    return 0;
}
0
