#include <iostream>
#include <vector>
#include "includes/Deck.h"

using std::cout;

int main(){

    Deck deck;
    Deck player1_hand;
    Deck player2_hand;
    Deck player1_won_pile;
    Deck player2_won_pile;
    Deck battleground;

    deck.shuffle();

    std::tie(player1_hand, player2_hand) = deck.cut(deck.size()/2);


    return 0;
}