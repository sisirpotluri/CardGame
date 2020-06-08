#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include "Attack.h"

/* ----- CARD CLASS DEFINITION ----- */

class Card {
public:
    
    //elements
    static constexpr const char * const PYRO = "Pyro";
    static constexpr const char * const AERO = "Aero";
    static constexpr const char * const AQUA = "Aqua";
    static constexpr const char * const EARTH = "Earth";
    static constexpr const char * const SPECTRAL = "Spectral";
    static constexpr const char * const GLEAM = "Gleam";
    
    //forms
    static constexpr const char * const GRIFFIN = "Griffin";
    static constexpr const char * const PHOENIX = "Phoenix";
    static constexpr const char * const LEVIATHAN = "Leviathan";
    static constexpr const char * const BEHEMOTH = "Behemoth";
    static constexpr const char * const DJINN = "Djinn";
    
    Card();
    
    Card(const std::string &element_in, const std::string &form_in);
    
    void set_attack(const std::string &name,
                     const std::string &level, const int damage);
  
    std::string get_element() const;
    
    std::string get_form() const;
    
    bool is_origin_form() const;
    
    void reduce_health(int damage);
    
    int get_health();
    
    void reset();
    
    Attack get_attack(std::string choice);
    
    bool alive() const;
    
    Attack get_base();
    
    Attack get_ultra();
    
private:
    std::string element;
    std::string form;
    int health;
    Attack base;
    Attack ultra;
};

/* ------ CARD ARRAYS ------ */

//elements array
constexpr const char * const ELEMENTS[] = {
    
    Card::PYRO,
    Card::AERO,
    Card::AQUA,
    Card::EARTH,
    Card::SPECTRAL,
    Card::GLEAM
    
};
const int NUM_TYPES = 6;

//forms array
constexpr const char * const FORMS[] = {
    
    Card::GRIFFIN,
    Card::PHOENIX,
    Card::LEVIATHAN,
    Card::BEHEMOTH,
    Card::DJINN,

};
const int NUM_FORMS = 5;

std::ostream & operator<<(std::ostream &os, const Card &card);

bool operator==(const Card &lhs, const Card &rhs);

bool card_better(const Card &a, const Card &b,
                 const std::string &aura_in, int round);

#endif
