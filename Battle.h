#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include <vector>
#include "Warrior.h"
#include "Deck.h"

class Battle {
public:
    
    Battle();
    
    Battle(std::vector<std::string> warrior_info_in,
           const int battles_to_win_in);
    
    void play_game();
    
    void shuffle();
    
    void make_warriors();
    
    void give_cards();
    
    void cards_battle();
    
    void play_round_one();
    
    void play_round_two();
    
    void finish();
    
    void move_warriors();
    
private:
    Deck deck;
    Warrior * one;
    Warrior * two;
    Warrior * round_one_winner;
    Warrior * round_two_winner;
    std::vector<std::string> warriors_info;
    std::vector<Warrior *> warriors_ptrs;
    std::vector<Card> must_deal;
    std::vector<Card *> in_play;
    std::string aura;
    Card aura_card;
    int winner_index = 0;
    int loser_index = 0;
    int battles_to_win;
    int battle_count = 0;
    int round = 0;
    bool round_one_over = false;
    bool round_two_over = false;
    
};

#endif
