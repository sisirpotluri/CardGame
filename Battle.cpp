//
//  Battle.cpp
//  Cards
//
//  Created by Sisir Potluri on 6/5/20.
//  Copyright © 2020 Sisir Potluri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Battle.h"

using namespace std;

Battle::Battle(vector<string> warrior_info_in, const int battles_to_win_in)
    : warriors_info(warrior_info_in), battles_to_win(battles_to_win_in) {
        
        round = 1;
        deck = Deck();
        deck.set_attacks();
        
    }


void Battle::play_game() {
    
    if (battle_count == 0) {
        make_warriors();
    }
    
    while (warriors_ptrs[0] -> get_wins() != battles_to_win
           && warriors_ptrs[1] -> get_wins() != battles_to_win) {
    
        cout << "Battle " << (battle_count + 1) << " begins now!" << endl;
        
        for (int i = 0; i < (battle_count + 1); i++) {
            shuffle();
        }
        
        give_cards();
        
        round = 1;
        
        play_round_one();
        
        round = 2;
        
        play_round_two();
        
        finish();
        
        battle_count++;
        
        move_warriors();
        
    }
    
    cout << "The war is over!" << endl;
    if (warriors_ptrs[0] -> get_wins() > warriors_ptrs[1] -> get_wins()) {
        cout << *warriors_ptrs[0] << " wins the war!" << endl;
    }
    if (warriors_ptrs[1] -> get_wins() > warriors_ptrs[0] -> get_wins()) {
        cout << *warriors_ptrs[1] << " wins the war!" << endl;
    }
    delete one;
    delete two;
    cout << endl;
    
}


void Battle::shuffle() {
    
    deck.shuffle_deck();
    
}


void Battle::make_warriors() {
    
    one = Warrior_factory(warriors_info[0], warriors_info[1]);
    two = Warrior_factory(warriors_info[2], warriors_info[3]);
    
    warriors_ptrs.push_back(one);
    warriors_ptrs.push_back(two);
    
}


void Battle::give_cards() {
    
    for (int i = 0; i < 3; i++) {
        if (deck.empty()) {
            deck.reset_deck(); 
        }
        warriors_ptrs[0] -> give_card(deck.deal_card(), 1);
    }
    for (int i = 0; i < 4; i++) {
        if (deck.empty()) {
            deck.reset_deck();
        }
        warriors_ptrs[1] -> give_card(deck.deal_card(), 1);
    }
    for (int i = 0; i < 4; i++) {
        if (deck.empty()) {
            deck.reset_deck();
        }
        warriors_ptrs[0] -> give_card(deck.deal_card(), 1);
    }
    for (int i = 0; i < 3; i++) {
        if (deck.empty()) {
            deck.reset_deck();
        }
        warriors_ptrs[1] -> give_card(deck.deal_card(), 1);
    }
    
    must_deal.push_back(deck.deal_card());
    
    must_deal.push_back(deck.deal_card());
    
    must_deal.push_back(deck.deal_card());
    
    must_deal.push_back(deck.deal_card());
    
    cout << "Cards have been dealt." << endl;
    
    aura_card = must_deal[0];
    
    cout << "Aura Creator is " << aura_card << "." << endl;
    
    aura = aura_card.get_element();
    
    cout << aura << " radiates through the terrain." << endl;
    
    cout << endl;
    
}

void Battle::cards_battle() {
    
    cout << *in_play[0] << " vs " << *in_play[1] << endl;
    
    if (card_better(*in_play[0], *in_play[1], aura, round)) {
        winner_index = 0;
        cout << *in_play[0] << " wins!" << endl;
        in_play[1] -> reduce_health(70);
        in_play[0] -> reduce_health(30);
    }
    
    else if (card_better(*in_play[1], *in_play[0], aura, round)) {
        winner_index = 1;
        cout << *in_play[1] << " wins!" << endl;
        in_play[0] -> reduce_health(70);
        in_play[1] -> reduce_health(30);
    }
    
    else {
        Attack zero_choice = warriors_ptrs[0] -> choose_attack(in_play[0]);
        Attack one_choice = warriors_ptrs[1] -> choose_attack(in_play[1]);
        
        int damage_zero = zero_choice.get_strength();
        int damage_one = one_choice.get_strength();
        
        if (damage_zero == damage_one) {
            cout << "Both attacks fused and exploded. Both cards got damaged!" << endl;
            in_play[0] -> reduce_health(70);
            in_play[1] -> reduce_health(70);
        }
        
        else {
            in_play[1] -> reduce_health(damage_zero);
            
            cout << *in_play[0] << " did " << damage_zero <<
            " damage to " << *in_play[1] << endl;
            
            in_play[0] -> reduce_health(damage_one);
            
            cout << *in_play[1] << " did " << damage_one <<
            " damage to " << *in_play[0] << endl;
        }
        
    }
    
    in_play.erase(in_play.begin());
    in_play.erase(in_play.begin());
    
    cout << endl;
    
}

void Battle::play_round_one() {
    
    cout << "Round one begins!" << endl;
    
    round = 1;
    
    while (warriors_ptrs[0] -> has_cards(1)
           && warriors_ptrs[1] -> has_cards(1)) {
        
        in_play.push_back(warriors_ptrs[0] -> play_card_round_one(aura));
        cout << *in_play[0] << " ( Health: " << in_play[0] -> get_health() << " ) summoned by " << *warriors_ptrs[0] << "." << endl;
        in_play.push_back(warriors_ptrs[1] -> play_card_round_one(aura));
        cout << *in_play[1] << " ( Health: " << in_play[1] -> get_health() << " ) summoned by " << *warriors_ptrs[1] << "." << endl;
        
        cards_battle();
        
    }
    
    
    if (!(warriors_ptrs[1] -> has_cards(1))) {
        
        round_one_winner = warriors_ptrs[0];
        cout << *round_one_winner << " wins round one! " << endl;
        warriors_ptrs[0] -> reset_hand();
        warriors_ptrs[1] -> reset_hand();
        warriors_ptrs[0] -> deal_cards(must_deal, warriors_ptrs[1]);
      
    }
    
    else {
        
        round_one_winner = warriors_ptrs[1];
        cout << *round_one_winner << " wins round one! " << endl;
        warriors_ptrs[0] -> reset_hand();
        warriors_ptrs[1] -> reset_hand();
        warriors_ptrs[1] -> deal_cards(must_deal, warriors_ptrs[0]);
        
    }
    
    cout << endl;
    cout << "The aura disappeared from the terrain." << endl;
    cout << endl;
    
}

void Battle::play_round_two() {
    
    round = 2;
    
    cout << "Round two begins!" << endl;
    
    while (warriors_ptrs[0] -> has_cards(2)
           && warriors_ptrs[1] -> has_cards(2)) {
        
        in_play.push_back(warriors_ptrs[0] -> play_card_round_two());
        cout << *in_play[0] << " ( Health: " << in_play[0] -> get_health() << " ) summoned by " << *warriors_ptrs[0] << "." << endl;
        in_play.push_back(warriors_ptrs[1] -> play_card_round_two());
        cout << *in_play[1] << " ( Health: " << in_play[1] -> get_health() << " ) summoned by " << *warriors_ptrs[1] << "." << endl;
        
        cards_battle();
        
    }
    
    
    if (!(warriors_ptrs[1] -> has_cards(2))) {
        
        round_two_winner = warriors_ptrs[0];
        warriors_ptrs[0] -> add_win();
        cout << *round_two_winner << " wins the battle!" << endl;
        
    }
    
    else {
        
        round_two_winner = warriors_ptrs[1];
        warriors_ptrs[1] -> add_win();
        cout << *round_two_winner << " wins the battle!" << endl;
        
    }
    
    cout << endl;
    
}


void Battle::finish() {
    
    cout << "The battle is over!" << endl;
    
    cout << *warriors_ptrs[0] << " won " << warriors_ptrs[0] -> get_wins()
    << " battles." << endl;
    cout << *warriors_ptrs[1] << " won " << warriors_ptrs[1] -> get_wins()
    << " battles." << endl;
    
    warriors_ptrs[0] -> empty_hand();
    warriors_ptrs[1] -> empty_hand();
    
    cout << endl;
    
}

void Battle::move_warriors() {
    
    Warrior * temp = warriors_ptrs[0];
    warriors_ptrs[0] = warriors_ptrs[1];
    warriors_ptrs[1] = temp;
    
}
