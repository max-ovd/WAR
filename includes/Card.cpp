#include "Card.h"

Card::Card(int value, char suit){
    this->value = value;
    this->suit = suit;
}


int Card::getValue(){
    return value;
}

char Card::getSuit(){
    return suit;
}
