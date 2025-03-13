#include <iostream>
#include <vector>
#include "deck.h"

            
Deck::Deck(){
    for (int i = 1; i <= 14; i++) {
        for (int j = 0; j < 4; j++) {
            this->deck.push_back(i);
        }
    }
}

Deck::Deck(std::vector<int> deck) {
    this->deck = deck;
}

Deck Deck::shuffle(){
    // shuffle cards

    return deck;
}

int Deck::size(){
    return deck.size();
}

bool Deck::isEmpty(){
    return deck.size() == 0;
}

void Deck::print_cards(){
    for (int i : deck) {
        std::cout << i << "\n";
    }
}

std::pair<Deck, Deck> Deck::cut(const int N){
    if (N <= 0 || N >= deck.size()) {
        throw std::out_of_range("Cut index is out of bounds.");
    }

    Deck v1(std::vector<int>(deck.begin(), deck.begin() + N));
    Deck v2(std::vector<int>(deck.begin() + N, deck.end()));

    return std::pair<Deck, Deck> {v1, v2}; 
}
