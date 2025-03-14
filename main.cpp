#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "includes/Deck.h"

using std::cout;

int main(){

    std::map<int, std::string> cards = {
        {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"},
        {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}, {10, "10"},
        {11, "J"}, {12, "Q"}, {13, "K"}, {14, "A"}
    };

    Deck deck(14);
    Deck player1_hand;
    Deck player2_hand;
    Deck player1_won_pile;
    Deck player2_won_pile;
    Deck battle_hand;


    // Starting hands
    deck.shuffle();
    std::tie(player1_hand, player2_hand) = deck.cut(deck.size()/2);

    int rounds = 0;

    while (true) {
        rounds++;

        if (player1_hand.size() == 0) {
            if (player1_won_pile.size() == 0) {
                cout << "Player 2 won!" << "\n";
                break;
            }
            player1_hand = player1_won_pile;
            player1_hand.shuffle();
            player1_won_pile.clear();
        }
        if (player2_hand.size() == 0) {
            if (player2_won_pile.size() == 0) {
                cout << "Player 1 won!" << "\n";
                break;
            }
            player2_hand = player2_won_pile;
            player2_hand.shuffle();
            player2_won_pile.clear();
        }

        int p1 = player1_hand.pop();
        int p2 = player2_hand.pop();
        
        cout << cards[p1-1] << " vs. " << cards[p2-1] << "\n";

        battle_hand.add(p1);
        battle_hand.add(p2);


        if (p1 > p2) {
            player1_won_pile.add(battle_hand);
            battle_hand.clear();
            cout << "p1 WON!" << "\n";
            continue;
        }

        else if (p2 > p1) {
            player2_won_pile.add(battle_hand);
            battle_hand.clear();
            cout << "p2 WON!" << "\n";
            continue;
        }

        else {
            battle_hand.add(player1_hand.pop(2));
            battle_hand.add(player2_hand.pop(2));
        }
    }

    cout << rounds;
    return 0;
}

