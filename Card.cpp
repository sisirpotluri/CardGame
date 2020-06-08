//
//  Card.cpp
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

constexpr const char* const Card::PYRO;
constexpr const char* const Card::AERO;
constexpr const char* const Card::AQUA;
constexpr const char* const Card::EARTH;
constexpr const char* const Card::SPECTRAL;
constexpr const char* const Card::GLEAM;

constexpr const char* const Card::GRIFFIN;
constexpr const char* const Card::PHOENIX;
constexpr const char* const Card::LEVIATHAN;
constexpr const char* const Card::DJINN;

Card::Card() : element(PYRO), form(PHOENIX), health(100) {}

Card::Card(const std::string &element_in, const std::string &form_in)
    : element(element_in), form(form_in), health(100) {}

void Card::set_attack(const std::string &name,
                 const std::string &level, const int damage) {
    
    assert(level == "Base" || level == "Ultra");
    
    if (level == "Base") {
        base.set_name(name);
        base.set_strength(damage);
    }
    if (level == "Ultra") {
        ultra.set_name(name);
        ultra.set_strength(damage);
    }
    
}

string Card::get_element() const {
    return element;
}

string Card::get_form() const {
    return form;
}

bool Card::is_origin_form() const{
    
    if (element == PYRO && form == PHOENIX) {
        return true;
    }
    else if (element == AQUA && form == LEVIATHAN) {
        return true;
    }
    else if (element == EARTH && form == BEHEMOTH) {
        return true;
    }
    else if (element == AERO && form == GRIFFIN) {
        return true;
    }
    else if (element == SPECTRAL && form == DJINN) {
        return true;
    }
    else if (element == GLEAM && form == DJINN) {
        return true;
    }
    else {
        return false;
    }
    
}

void Card::reduce_health(int damage) {
    
    assert(damage == 50 || damage == 100);
    health -= damage;
    
}

bool Card::alive() const {
    
    if (health > 0) {
        return true;
    }
    else {
        return false;
    }
    
}

Attack Card::get_base() {
    return base;
}

Attack Card::get_ultra() {
    return ultra;
}

