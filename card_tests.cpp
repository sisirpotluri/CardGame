//
//  card_tests.cpp
//  Cards
//
//  Created by Sisir Potluri on 6/3/20.
//  Copyright © 2020 Sisir Potluri. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

void test_ctor();
void test_set_attack();
void test_origin_form();
void test_reduce_health_alive();

int main () {
    
    test_ctor();
    test_set_attack();
    test_origin_form();
    test_reduce_health_alive();
    
    cout << "ALL TESTS PASSED" << endl;
    
    return 0;
}

void test_ctor() {
    
    Card test_1;
    
    assert(test_1.get_element() == Card::PYRO);
    assert(test_1.get_form() == Card::PHOENIX);
    
    Card test_2 = Card(Card::GLEAM, Card::DJINN);
    
    assert(test_2.get_element() == Card::GLEAM);
    assert(test_2.get_form() == Card::DJINN);
    
    cout << "TEST PASSED" << endl;
    
}

void test_set_attack() {
    
    Card test = Card(Card::GLEAM, Card::DJINN);
    
    string level = "Base";
    
    test.set_attack("Ashen Spell", level, 50);
    
    Attack correct;
    
    correct.set_strength(50);
    
    correct.set_name("Ashen Spell");
    
    assert((test.get_base()).get_name() == correct.get_name());
    assert((test.get_base()).get_strength() == correct.get_strength());
    
    level = "Ultra";
    
    test.set_attack("Photon Spear", level, 100);
    
    correct.set_strength(100);
    
    correct.set_name("Photon Spear");
    
    assert((test.get_ultra()).get_name() == correct.get_name());
    assert((test.get_ultra()).get_strength() == correct.get_strength());
    
    cout << "TEST PASSED" << endl;
    
}

void test_origin_form() {
    
    Card test_1 = Card(Card::GLEAM, Card::DJINN);
    Card test_2 = Card(Card::SPECTRAL, Card::DJINN);
    Card test_3 = Card(Card::PYRO, Card::PHOENIX);
    Card test_4 = Card(Card::AQUA, Card::LEVIATHAN);
    Card test_5 = Card(Card::AERO, Card::GRIFFIN);
    Card test_6 = Card(Card::EARTH, Card::BEHEMOTH);
    
    Card test_7 = Card(Card::AERO, Card::BEHEMOTH);
    Card test_8 = Card(Card::PYRO, Card::GRIFFIN);
    Card test_9 = Card(Card::AQUA, Card::PHOENIX);
    Card test_10 = Card(Card::EARTH, Card::LEVIATHAN);

    assert(test_1.is_origin_form() == true);
    assert(test_2.is_origin_form() == true);
    assert(test_3.is_origin_form() == true);
    assert(test_4.is_origin_form() == true);
    assert(test_5.is_origin_form() == true);
    assert(test_6.is_origin_form() == true);
    
    assert(test_7.is_origin_form() == false);
    assert(test_8.is_origin_form() == false);
    assert(test_9.is_origin_form() == false);
    assert(test_10.is_origin_form() == false);
    
    cout << "TEST PASSED" << endl;
    
}

void test_reduce_health_alive() {
    
    Card test = Card(Card::AQUA, Card::GRIFFIN);
    
    test.reduce_health(50);
    
    assert(test.alive() == true);
    
    test.reduce_health(100);
    
    assert(test.alive() == false);
    
    cout << "TEST PASSED" << endl;
    
}

