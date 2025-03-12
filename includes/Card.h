#pragma once

class Card {
    private:
        int value;
        char suit;

    public:
        Card(int value, char suit);

        int getValue();
        char getSuit();
};