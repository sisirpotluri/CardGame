//
//  Attack.cpp
//  Cards
//
//  Created by Sisir Potluri on 6/3/20.
//  Copyright © 2020 Sisir Potluri. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <string>
#include "Attack.h"

using namespace std; 

Attack::Attack() : strength(0), name("Hit") {}

void Attack::set_name(const string &name_in) {
    name = name_in;
}

void Attack::set_strength(const int &strength_in) {
    assert(strength_in == 50 || strength_in == 100);
    strength = strength_in;
}

string Attack::get_name() const {
    return name;
}

int Attack::get_strength() const {
    return strength;
}

