#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Deck.h"

            
Deck::Deck(){
    this->deck = std::vector<int> {};
}

Deck::Deck(int n){
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            this->deck.push_back(i);
        }
    }
}

Deck::Deck(std::vector<int> deck) {
    this->deck = deck;
}

Deck& Deck::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);

    return *this;
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

    return {
        Deck(
            std::vector<int>(
                std::make_move_iterator(deck.begin()),
                std::make_move_iterator(deck.begin()+ N)
            )
        ),
        Deck(
            std::vector<int>(
                std::make_move_iterator(deck.begin()+N), 
                std::make_move_iterator(deck.end()))
        )
    };
}

int Deck::pop(){
    int popped_item = deck[0];
    deck.erase(deck.begin());
    
    return popped_item;
}

std::vector<int> Deck::pop(int n) {
    std::vector<int> output;

    for (int i = 0; i < n; i++) {
        if (deck.size() <= 1) {
            return output;
        }
        output.push_back(deck.front());
        deck.erase(deck.begin());
    }

    return output;
}

void Deck::add(int x){
    deck.insert(deck.end(), x);
}

void Deck::add(const Deck& x) {
    deck.insert(deck.end(), x.deck.begin(), x.deck.end());
}

auto Deck::begin() -> std::vector<int>::iterator { // undestand this line
    return deck.begin();
}

auto Deck::end() -> std::vector<int>::iterator{
    return deck.end();
}

void Deck::clear(){
    deck.clear();
}