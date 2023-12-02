#include "include/BoardGame_Classes.hpp"
#include <iomanip>

five_by_five::five_by_five() {
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
};

bool five_by_five::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0) && n_moves < 24) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else
        return false;
};

void five_by_five::display_board() {
    for (int i: {0, 1, 2, 3, 4}) {
        cout << "\n| ";
        for (int j: {0, 1, 2, 3, 4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
};

bool five_by_five::is_winner() {};

bool five_by_five::is_draw() {};

bool five_by_five::game_is_over() {};