#include "include/BoardGame_Classes.hpp"
#include <bits/stdc++.h>

four_in_a_row::four_in_a_row() {
    n_rows = 6;
    n_cols = 7;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool four_in_a_row::update_board(int x, int y, char mark) {
// Only update if move is valid
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else
        return false;
}

void four_in_a_row::display_board() {
    for (int i = 0; i < 6; ++i) {
        cout << "\n| ";
        for (int j = 0; j < 7; ++j) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool four_in_a_row::is_winner() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == board[i][j + 1] == board[i][j + 2] == board[i][j + 3])
                return true;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (board[i][j] == board[i + 1][j] == board[i + 2][j] == board[i + 3][j])
                return true;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == board[i + 1][j + 1] == board[i + 2][j + 2] == board[i + 3][j + 3])
                return true;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 6; j >= 3; --j) {
            if (board[i][j] == board[i + 1][j - 1] == board[i + 2][j - 2] == board[i + 3][j - 3])
                return true;
        }
    }
    return false;
}

bool four_in_a_row::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool four_in_a_row::game_is_over() {
    return n_moves >= 42;
}
