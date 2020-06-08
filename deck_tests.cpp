//
//  deck_tests.cpp
//  Cards
//
//  Created by Sisir Potluri on 6/4/20.
//  Copyright © 2020 Sisir Potluri. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include "Deck.h"

using namespace std;

void test_ctor_reset_empty();
void test_shuffle();

int main() {
    
    test_ctor_reset_empty();
    test_shuffle();
    
    cout << "ALL TESTS PASSED" << endl;
    return 0;
    
}

void test_ctor_reset_empty() {
    
    Deck test;
    
    Card hold = test.deal_card();
    
    Card correct_1 = Card(Card::PYRO, Card::GRIFFIN);
    
    assert(hold == correct_1);
    
    for (int i = 0; i < 6; i++) {
        hold = test.deal_card();
    }
    
    Card correct_2 = Card(Card::AERO, Card::LEVIATHAN);
    
    assert(hold == correct_2);
    
    for (int i = 0; i < 11; i++) {
        hold = test.deal_card();
    }
    
    Card correct_3 = Card(Card::GLEAM, Card::DJINN);
    
    assert(hold == correct_3);
    
    assert(test.empty() == true);
    
    test.reset_deck();
    
    assert(test.empty() == false);
    
    hold = test.deal_card();
    
    assert(hold == correct_1);
    
    cout << "TEST PASSED" << endl;
    
}

void test_shuffle() {
    
    Deck unshuffled;
    Deck shuffled;
    
    shuffled.shuffle_deck();
    
    Card shuffled_card;
    Card unshuffled_card;
    
    for (int i = 0; i < 18; i++) {
        unshuffled_card = unshuffled.deal_card();
        cout << unshuffled_card << endl;
    }
    
    for (int i = 0; i < 18; i++) {
        shuffled_card = shuffled.deal_card();
        cout << shuffled_card << endl;
    }
    
    string different_prompt;
    
    cout << "ARE THE RESULTS DIFFERENT? Enter 'yes' or 'no'" << endl;
    
    cin >> different_prompt;
    
    if (different_prompt == "yes") {
        cout << "TEST PASSED" << endl;
    }
    else {
        cout << "TEST DIDN'T PASS" << endl;
    }
    
}
