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
    
    assert(damage == 30 || damage == 70 || damage == 0);
    health -= damage;
    
}

int Card::get_health() {
    return health;
}

void Card::reset() {
    
    health = 100;
    
}

Attack Card::get_attack(string choice) {
    
    Attack empty;
    empty.set_name("Missed");
    empty.set_strength(0);
    
    if (choice == "base") {
        cout << *this << " used " << base << endl;
        return base;
    }
    else if (choice == "ultra") {
        cout << *this << " used " << ultra << endl;
        return ultra;
    }
    else {
        cout << *this << " " << empty << endl;
        return empty;
    }
    
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

std::ostream & operator<<(std::ostream &os, const Card &card) {
    os << card.get_element() << " " << card.get_form();
    return os;
}

bool operator==(const Card &lhs, const Card &rhs) {
    if (lhs.get_form() == rhs.get_form() &&
        lhs.get_element() == rhs.get_element()) {
        return true;
    }
    else {
        return false;
    }
}

bool card_better(const Card &a, const Card &b,
                const std::string &aura_in, int round) {
    
    assert(round == 1 || round == 2);
    
    if (round == 1) {
        if (a.is_origin_form() && a.get_element() == aura_in) {
            return true;
        }
        else if (a.is_origin_form() && a.get_element() == aura_in) {
            return false;
        }
        else if (a.is_origin_form()) {
            if (b.is_origin_form()) {
                return false;
            }
            else {
                return true;
            }
        }
        else if (b.is_origin_form()) {
            if (a.is_origin_form()) {
                return false;
            }
            else {
                return false;
            }
        }
        else if (a.get_element() == aura_in) {
            if (b.get_element() == aura_in) {
                return false;
            }
            else {
                return true;
            }
        }
        else if (b.get_element() == aura_in) {
            if (a.get_element() == aura_in) {
                return false;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    
    if (round == 2) {
        if (a.is_origin_form()) {
            if (b.is_origin_form()) {
                return false;
            }
            else {
                return true;
            }
        }
        else if (b.is_origin_form()) {
            if (a.is_origin_form()) {
                return false;
            }
            else {
                return false;
            }
        }
        else if (a.get_element() == aura_in) {
            if (b.get_element() == aura_in) {
                return false;
            }
            else {
                return true;
            }
        }
        else if (b.get_element() == aura_in) {
            if (a.get_element() == aura_in) {
                return false;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    
    return false;
    
}

