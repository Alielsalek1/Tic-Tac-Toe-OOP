#include <iostream>
using namespace std;
#include "include/BoardGame_Classes.hpp"

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1) players[1] = new Player (2, 'o');
    else players[1] = new RandomPlayer ('o', 3);    //Player pointer points to child

    cout << "choose a type of game to play from 1-3 :\n"
            "1 - 3x3\n"
            "2 - pyramid board\n"
            "3 - 5x5\n"
            "4 - four in a row\n";
    int c; cin >> c;
    if (c == 1) {
        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
        system ("pause");
    } else if (c == 2) {
        GameManager x_o_game(new pyramid_board(), players);
        x_o_game.run();
        system ("pause");
    } else if (c == 3){
        for (auto & player : players) delete player;
        players[0] = new fiveByFivePlayer('x', players[0]);
        players[1] = new fiveByFivePlayer('o', players[1]);
        GameManager x_o_game(new five_by_five(players), players);
        x_o_game.run();
        system ("pause");
    } else {
        GameManager x_o_game(new four_in_a_row(), players);
        x_o_game.run();
        system ("pause");
    }
    return 0;
}
