#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "Card.h"

class Deck {
public:
    Deck();
    
    void set_attacks();
    
    Card deal_card();
    
    void reset_deck();
   
    void shuffle_deck();
    
    bool empty() const;
    
    
private:
    int index;
    static const int DECK_SIZE = 18;
    std::array<Card, DECK_SIZE> cards;
    
};






#endif
