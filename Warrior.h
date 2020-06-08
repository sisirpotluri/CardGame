#ifndef WARRIOR_H
#define WARRIOR_H
/* Player.h
 *
 * Euchre player interface
 * Project UID 1d9f47bfc76643019cfbf037641defe1
 *
 * by Andrew DeOrio
 * awdeorio@umich.edu
 * 2014-12-21
 */

#include <string>
#include <vector>
#include "Card.h"


class Warrior {
public:
    
    virtual const std::string & get_name() const = 0;
    
    virtual void give_card(const Card &c, int round) = 0;
    
    virtual Card * play_card_round_one(const std::string &aura_in) = 0;
    
    virtual Card * play_card_round_two() = 0;
    
    virtual Attack choose_attack(Card * card_in) = 0;

    virtual void deal_cards(std::vector<Card> &dealt, Warrior * opponent) = 0;
    
    virtual bool has_cards(int round) = 0;
    
    virtual void add_win() = 0;
    
    virtual int get_wins() = 0;
    
    virtual void reset_hand() = 0;
    
    virtual void empty_hand() = 0;
    
    static const int MAX_CARDS_FIRST = 7;
    
    static const int MAX_CARDS_SECOND = 9;
 
    virtual ~Warrior() {}
    
};

Warrior * Warrior_factory(const std::string &name_in, const std::string &type_in);

std::ostream & operator<<(std::ostream &os, const Warrior &w);

#endif
