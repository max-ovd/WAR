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
        int pop();
        std::vector<int> pop(int n);
        void add(int x);
        void add(Deck x);
        Deck clear();
        auto begin() -> std::vector<int>::iterator;
        auto end() -> std::vector<int>::iterator;               
};