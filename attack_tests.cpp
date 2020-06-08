//
//  attack_tests.cpp
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

void test_ctor_setters_getters();

int main () {
    
    test_ctor_setters_getters();
    
    cout << "ALL TESTS PASSED" << endl;
    
    return 0;
}

void test_ctor_setters_getters() {
    
    Attack test;
    
    assert(test.get_name() == "Hit");
    assert(test.get_strength() == 0);
    
    test.set_name("Blue Tempest");
    test.set_strength(50);
    
    assert(test.get_name() == "Blue Tempest");
    assert(test.get_strength() == 50);
    
    cout << "TEST PASSED" << endl;
    
}
