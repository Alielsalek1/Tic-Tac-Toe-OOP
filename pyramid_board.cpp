#include "include/BoardGame_Classes.hpp"
#include <bits/stdc++.h>

pyramid_board::pyramid_board() {
    n_rows = 3;
    n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool pyramid_board::update_board(int x, int y, char mark) {
// Only update if move is valid
    if (((x == 0 && y == 2) ||
    (x == 1 && y >= 1 && y <= 3) ||
    (x == 2 && y >= 0 && y <= 4)) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else
        return false;
}

void pyramid_board::display_board() {
    int up = 2, low = 2;
    for (int i: {0, 1, 2}) {
        cout << "\n| ";
        for (int j = 0; j < low; ++j) cout << "        |";
        for (int j = low; j <= up; ++j) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        low--, up++;
        cout << "\n----------------------------------------";
    }
    cout << endl;
}
bool pyramid_board::is_winner() {
    // check diagonals
    if (board[0][2] == board[1][3] && board[1][3] == board[2][4] && isalpha(board[0][2])) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && isalpha(board[0][2])) return true;
    // check mid
    if (board[1][1] == board[1][2] && board[1][2] == board[1][3] && isalpha(board[1][1])) return true;
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && isalpha(board[0][2])) return true;
    for (int i = 0; i < 3; ++i) {
        if (board[2][i] == board[2][i + 1] && board[2][i + 1] == board[2][i + 2] && isalpha(board[2][i])) return true;
    }
    return false;
}

bool pyramid_board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool pyramid_board::game_is_over() {
    return n_moves >= 9;
}