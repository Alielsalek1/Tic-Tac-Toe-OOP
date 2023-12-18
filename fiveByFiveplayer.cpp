#include "BoardGame_Classes.hpp"

void fiveByFivePlayer::get_move(int &x, int &y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

fiveByFivePlayer::fiveByFivePlayer(char symbol, Player *pPlayer) : Player(symbol) {
    this->symbol = pPlayer->get_symbol();
    this->name = pPlayer->to_string();
}
