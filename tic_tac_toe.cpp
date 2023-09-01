#include <iostream>
#include <vector>

// Function to display the game board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false; // There's an empty cell, game is not a draw
        }
    }
    return true; // All cells are filled, game is a draw
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        displayBoard(board);
        std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
        int row, col;
        std::cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            gameWon = checkWin(board, currentPlayer);
            gameDraw = checkDraw(board);

            if (!gameWon && !gameDraw) {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    displayBoard(board);
    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}
