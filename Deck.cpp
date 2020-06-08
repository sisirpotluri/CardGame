//
//  Deck.cpp
//  Cards
//
//  Created by Sisir Potluri on 6/4/20.
//  Copyright © 2020 Sisir Potluri. All rights reserved.
//

#include <stdlib.h>
#include "Deck.h"

using namespace std;

Deck::Deck() {
    index = 0;
    for (int e = 0; e < NUM_TYPES - 2; e++) {
        for (int f = 0; f < NUM_FORMS - 1; f++) {
            cards[index] = Card(ELEMENTS[e], FORMS[f]);
            index++;
        }
    }
    cards[index] = Card(Card::SPECTRAL, Card::DJINN);
    index++;
    cards[index] = Card(Card::GLEAM, Card::DJINN);
    index++;
    reset_deck();
}

void Deck::set_attacks() {
    cards[0].set_attack("Inferno Claw", "Base", 30);
    cards[0].set_attack("Ultra Inferno Assault", "Ultra", 70);
    cards[1].set_attack("Magma Wing", "Base", 30);
    cards[1].set_attack("Ultra Flaring Ascent", "Ultra", 70);
    cards[2].set_attack("Searing Wave", "Base", 30);
    cards[2].set_attack("Ultra Obsidian Trident", "Ultra", 70);
    cards[3].set_attack("Tremor Blaze", "Base", 30);
    cards[3].set_attack("Ultra Volcanic Rage", "Ultra", 70);
    cards[4].set_attack("Twister Roar", "Base", 30);
    cards[4].set_attack("Ultra Twister Tackle", "Ultra", 70);
    cards[5].set_attack("Hurricane Wing", "Base", 30);
    cards[5].set_attack("Ultra Rapid Wind", "Ultra", 70);
    cards[6].set_attack("Cyclone Spout", "Base", 30);
    cards[6].set_attack("Ultra Shredding Cyclone", "Ultra", 70);
    cards[7].set_attack("Wind Crusher", "Base", 30);
    cards[7].set_attack("Ultra Gale Destruction", "Ultra", 70);
    cards[8].set_attack("Cerulean Wrath", "Base", 30);
    cards[8].set_attack("Ultra Blue Tsunami", "Ultra", 70);
    cards[9].set_attack("Blue Blaze", "Base", 30);
    cards[9].set_attack("Ultra Freezing Flare", "Ultra", 70);
    cards[10].set_attack("Tidal Oblivion", "Base", 30);
    cards[10].set_attack("Ultra Ruinous Wave", "Ultra", 70);
    cards[11].set_attack("Geyser Storm", "Base", 30);
    cards[11].set_attack("Ultra Crashing Spout", "Ultra", 70);
    cards[12].set_attack("Sand Crush", "Base", 30);
    cards[12].set_attack("Ultra Sandy Rush", "Ultra", 70);
    cards[13].set_attack("Rocky Tornado", "Base", 30);
    cards[13].set_attack("Ultra Stone Break", "Ultra", 70);
    cards[14].set_attack("Subzero Quake", "Base", 30);
    cards[14].set_attack("Ultra Tidal Tremor", "Ultra", 70);
    cards[15].set_attack("Tectonic Terror", "Base", 30);
    cards[15].set_attack("Ultra Wrathful Sierra", "Ultra", 70);
    cards[16].set_attack("Sinister Glare", "Base", 30);
    cards[16].set_attack("Ultra Evil Nightmare", "Ultra", 70);
    cards[17].set_attack("Ethereal Ray", "Base", 30);
    cards[17].set_attack("Ultra Divine Pulse", "Ultra", 70);
    
}

Card Deck::deal_card() {
    assert(!empty());
    Card result = cards[index];
    index++;
    return result;
}

void Deck::reset_deck() {
    index = 0;
}

void Deck::shuffle_deck() {
    
    std::array<Card, DECK_SIZE> temp;
    int count_even = 1;
    int count_odd = DECK_SIZE / 2;
    
    for (int s = 0; s < 3; s++) {
        count_even = 1;
        count_odd = DECK_SIZE / 2;
        for (int i = DECK_SIZE - 1; i >= 0; i--) {
            if (i % 2 == 0) {
                temp[i] = cards[i + count_even];
                count_even++;
            }
            else {
                temp[i] = cards[i - count_odd];
                count_odd--;
            }
        }
        for (int j = 0; j < DECK_SIZE; j++) {
            cards[j] = temp[j];
        }
    }
    
}

bool Deck::empty() const {
    if (index == 18) {
        return true;
    }
    else {
        return false;
    }
}
