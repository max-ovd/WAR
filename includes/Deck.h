#pragma once

class Deck{
    private:
        std::vector<int> deck;
        

    public:
        // Constructors
        Deck();
        Deck(std::vector<int> deck);

        // Methods
        Deck shuffle();
        void print_cards();
        int size();
        bool isEmpty();
        std::pair<Deck, Deck> cut(const int N);

};