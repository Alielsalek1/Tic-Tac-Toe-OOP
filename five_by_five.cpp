#include "include/BoardGame_Classes.hpp"
#include <iomanip>

five_by_five::five_by_five(Player *playerPtr[2]){
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
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

bool five_by_five::game_is_over() {
    if (n_moves < 25) return false;
    int winsCnt[2];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            char c = board[i][j];
            if (!c) continue;
            int cnt{0};
            for (int k = 1; k <= 2; ++k) {
                if (j + k < 5 and board[i][j + k] == c) cnt++;
            }
            winsCnt[c == 'O'] += cnt == 3;
            cnt = 0;
            for (int k = 1; k <= 2; ++k) {
                if (i + k < 5 and board[i + k][j] == c) cnt++;
            }
            winsCnt[c == 'O'] += cnt == 3;
            cnt = 0;
            for (int k = 1; k <= 2; ++k) {
                if (i + k < 5 and j + k < 5 and board[i + k][j + k] == c) cnt++;
            }
            winsCnt[c == 'O'] += cnt == 3;
        }
        if (winsCnt[0] > winsCnt[1]) {
            cout << players[0]->to_string() << " winsCnt";
        } else if (winsCnt[1] > winsCnt[0]) {
            cout << players[1]->to_string() << " winsCnt";
        } else {
            cout << "Draw!" << endl;
        }
    }
}

bool five_by_five::is_winner() {
    return false;
}

bool five_by_five::is_draw() {
    return false;
}
