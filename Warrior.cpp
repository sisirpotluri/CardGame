//
//  Warrior.cpp
//  Cards
//
//  Created by Sisir Potluri on 6/4/20.
//  Copyright © 2020 Sisir Potluri. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include "Warrior.h"

using namespace std;

class Bot : public Warrior {
public:
    
    Bot(const string &name_in)
    : name(name_in) {}
    
    const std::string & get_name() const override {
        return name;
    }
    
    void give_card(const Card &c, int round) override {
        
        assert(round == 1 || round == 2);
        if (round == 1) {
            assert(hand_one_size <= MAX_CARDS_FIRST);
        }
        if (round == 2) {
            assert(hand_two_size <= MAX_CARDS_SECOND);
        }
        
        if (round == 1) {
            hand_one.push_back(c);
            hand_one_size++;
        }
        else if (round == 2) {
            hand_two.push_back(c);
            hand_two_size++;
        }

    }
    
    Card * play_card_round_one(const string &aura_in) override {
        
        cout << "Player " << *this << "'s turn." << endl;
        
        int play_index = 0;
        
        for (int i = 0; i < hand_one_size; i++) {
            if (hand_one[i].alive()) {
                play_index = i;
            }
        }
        
        for (int i = 0; i < hand_one_size; i++) {
            if (card_better(hand_one[i], hand_one[play_index], aura_in, 1)
                && hand_one[i].alive()) {
                play_index = i;
            }
        }
        
        cout << endl;
        
        return &hand_one[play_index];
        
    }
    
    Card * play_card_round_two() override {
        
        cout << "Player " << *this << "'s turn." << endl;
        
        int play_index = 0;
        
        for (int i = 0; i < hand_two_size; i++) {
            if (hand_two[i].alive()) {
                play_index = i;
            }
        }
        
        string aura = "None";
        
        for (int i = 0; i < hand_two_size; i++) {
            if (card_better(hand_two[i], hand_two[play_index], aura, 2)
                && hand_two[i].alive()) {
                play_index = i;
            }
        }
        
        cout << endl;
        
        return &hand_two[play_index];
        
    }
    
    Attack choose_attack(Card * card_in) override{
        Attack choice;
        
        cout << "Player " << *this << "'s turn." << endl;
        
        if (card_in -> get_health() > 50) {
            choice = card_in -> get_ultra();
            cout << *this << " chose " << choice << endl;
        }
        else {
            choice = card_in -> get_base();
            cout << *this << " chose " << choice << endl;
        }
        
        cout << endl;
        
        return choice;
    }
    
    void deal_cards(vector<Card> &dealt, Warrior * opponent) override {
        
        Card deal = dealt[0];
        int deal_index = 0;
        
        int cards_left = 4;
        
        string aura = "None";
        
        cout << "Player " << *this << " deals cards." << endl;

        for (int i = 0; i < cards_left; i++) {
            if (!card_better(dealt[i], deal, aura, 2)) {
                deal = dealt[i];
                deal_index = i;
            }
        }
        
        cards_left--;
        
        opponent -> give_card(deal, 2);
        
        cout << "Player " << *this << " gave " << *opponent << " " << deal << endl;
        
        dealt.erase(dealt.begin() + deal_index);
        
        deal = dealt[0];
        
        deal_index = 0;
        
        for (int i = 0; i < cards_left; i++) {
            if (!card_better(dealt[i], deal, aura, 2)) {
                deal = dealt[i];
                deal_index = i;
            }
        }
        
        opponent -> give_card(deal, 2);
        
        cout << "Player " << *this << " gave " << *opponent << " " << deal << endl;
        
        dealt.erase(dealt.begin() + deal_index);
        
        give_card(dealt[1], 2);
        
        give_card(dealt[0], 2);
        
        cout << endl;
        
    }
    
    bool has_cards(int round) override {
        
        if (round == 1) {
            for (int i = 0; i < hand_one_size; i++) {
                if (hand_one[i].alive()) {
                    return true;
                }
            }
        }
        
        if (round == 2) {
            for (int i = 0; i < hand_two_size; i++) {
                if (hand_two[i].alive()) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
    
    void add_win() override {
        wins++;
    }
    
    int get_wins() override {
        return wins;
    }
    
    void reset_hand() override {
        for (int i = 0; i < hand_one_size; i++) {
            hand_one[i].reset();
            give_card(hand_one[i], 2);
        }
    }
    
    void empty_hand() override {
        for (int i = 0; i < 7; i++) {
            hand_one.erase(hand_one.begin());
            hand_one_size = 0;
        }
        for (int i = 0; i < 9; i++) {
            hand_two.erase(hand_two.begin());
            hand_two_size = 0;
        }
    }
    
    static const int MAX_CARDS_FIRST = 7;
    
    static const int MAX_CARDS_SECOND = 9;
    
private:
    string name;
    vector<Card> hand_one;
    vector<Card> hand_two;
    int hand_one_size = 0;
    int hand_two_size = 0;
    int wins = 0;
   
};

class Real : public Warrior {
public:
    
    Real(const string &name_in)
    : name(name_in) {}
    
    const std::string & get_name() const override {
        return name;
    }
    
    void give_card(const Card &c, int round) override {
        
        assert(round == 1 || round == 2);
        if (round == 1) {
            assert(hand_one_size <= MAX_CARDS_FIRST);
        }
        if (round == 2) {
            assert(hand_two_size <= MAX_CARDS_SECOND);
        }
        
        if (round == 1) {
            hand_one.push_back(c);
            hand_one_size++;
        }
        else if (round == 2) {
            hand_two.push_back(c);
            hand_two_size++;
        }
        
    }
    
    Card * play_card_round_one(const string &aura_in) override {
        
        int play_index = 0;
        
        cout << "Player " << *this << "'s turn." << endl;
        
        cout << "Current cards:" << endl;
        for (int i = 0; i < hand_one_size; i++) {
            cout << "Index " << i << " is " << hand_one[i] <<
            " | Health: " << (hand_one[i]).get_health() << endl;
        }
        
        cout << "Choose a card to play by its index: " << endl;
        
        cin >> play_index;
        
        while(!(play_index > -1 && play_index < hand_one_size)) {
            cout << "Please enter a valid index." << endl;
            cin >> play_index;
        }
        
        while (!(hand_one[play_index]).alive()) {
            cout << "That card has no health. Summon another card." << endl;
            cout << "Current cards:" << endl;
            for (int i = 0; i < hand_one_size; i++) {
                cout << "Index " << i << " is " << hand_one[i] <<
                " | Health: " << (hand_one[i]).get_health() << endl;
            }
            cout << "Choose a card to play by its index: " << endl;
            cin >> play_index;
        }
        
        cout << endl;
        
        return &hand_one[play_index];
        
    }
    
    Card * play_card_round_two() override {
        
        int play_index = 0;
        
        cout << "Player " << *this << "'s turn." << endl;
        
        cout << "Current cards:" << endl;
        for (int i = 0; i < hand_two_size; i++) {
            cout << "Index " << i << " is " << hand_two[i] <<
            " | Health: " << (hand_two[i]).get_health() << endl;
        }
        
        cout << "Choose a card to play by its index: " << endl;
        
        cin >> play_index;
        
        while(!(play_index > -1 && play_index < hand_two_size)) {
            cout << "Please enter a valid index." << endl;
            cin >> play_index;
        }
        
        while (!(hand_two[play_index]).alive()) {
            cout << "That card has no health. Summon another card." << endl;
            cout << "Current cards:" << endl;
            for (int i = 0; i < hand_two_size; i++) {
                cout << "Index " << i << " is " << hand_two[i] <<
                " | Health: " << (hand_two[i]).get_health() << endl;
            }
            cout << "Choose a card to play by its index: " << endl;
            cin >> play_index;
        }
        
        cout << endl;
        
        return &hand_two[play_index];
        
    }
    
    Attack choose_attack(Card * card_in) override{
        
        Attack choice;
        
        string choice_attack;
        
        cout << "Player " << *this << ", please choose an attack to use." << endl;
        
        cout << "Base Attack: " << card_in -> get_base() << endl;
        
        cout << "Ultra Attack: " << card_in -> get_ultra() << endl;
        
        cout << "Choose an attack to use => enter either 'base' or 'ultra' to choose." << endl;
        
        cin >> choice_attack;
        
        while(!(choice_attack == "base" || choice_attack == "ultra"
                || choice_attack == "Base" || choice_attack == "Ultra")) {
            cout << "Please choose a valid attack." << endl;
            cin >> choice_attack;
        }
        
        if (choice_attack == "base" || choice_attack == "Base") {
            choice = card_in -> get_base();
            cout << *this << " chose " << choice << endl;
        }
        else if (choice_attack == "ultra" || choice_attack == "Ultra") {
            choice = card_in -> get_ultra();
            cout << *this << " chose " << choice << endl;
        }
        
        cout << endl;
        
        return choice;
        
    }
    
    void deal_cards(vector<Card> &dealt, Warrior * opponent) override {
        
        Card deal = dealt[0];
        int deal_index = 0;
        
        int cards_left = 4;
        
        cout << "Player " << *this << " deals cards." << endl;
        
        cout << "Cards to be dealt:" << endl;
        for (int i = 0; i < cards_left; i++) {
            cout << "Index " << i << " is " << dealt[i] << endl;
        }
        
        cards_left--;
        
        cout << "Choose a card to deal to your opponent by its index: " << endl;
        
        cin >> deal_index;
        
        while(!(deal_index >= 0 && deal_index <= 4)) {
            cout << "Please choose a valid index." << endl;
            cin >> deal_index;
        }
        
        deal = dealt[deal_index];
        
        opponent -> give_card(deal, 2);
        
        cout << "Player " << *this << " gave " << *opponent << " " << deal << endl;
        
        dealt.erase(dealt.begin() + deal_index);
        
        cout << "Cards to be dealt:" << endl;
        for (int i = 0; i < cards_left; i++) {
            cout << "Index " << i << " is " << dealt[i] << endl;
        }

        cout << "Choose another card to deal to your opponent by its index: " << endl;
        
        cin >> deal_index;
        
        while(!(deal_index >= 0 && deal_index <= 3)) {
            cout << "Please choose a valid index." << endl;
            cin >> deal_index;
        }
        
        deal = dealt[deal_index];
        
        opponent -> give_card(deal, 2);
        
        cout << "Player " << *this << " gave " << *opponent << " " << deal << endl;
        
        dealt.erase(dealt.begin() + deal_index);

        give_card(dealt[1], 2);
        
        give_card(dealt[0], 2);
        
        cout << endl;
        
    }
    
    bool has_cards(int round) override {
        if (round == 1) {
            for (int i = 0; i < hand_one_size; i++) {
                if (hand_one[i].alive()) {
                    return true;
                }
            }
        }
        
        if (round == 2) {
            for (int i = 0; i < hand_two_size; i++) {
                if (hand_two[i].alive()) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    void add_win() override {
        wins++;
    }
    
    int get_wins() override {
        return wins;
    }
    
    void reset_hand() override{
        for (int i = 0; i < hand_one_size; i++) {
            hand_one[i].reset();
            give_card(hand_one[i], 2);
        }
    }
    
    void empty_hand() override {
        for (int i = 0; i < 7; i++) {
            hand_one.erase(hand_one.begin());
        }
        for (int i = 0; i < 9; i++) {
            hand_two.erase(hand_two.begin());
        }
        hand_one_size = 0;
        hand_two_size = 0;
        
    }
    
    static const int MAX_CARDS_FIRST = 7;
    
    static const int MAX_CARDS_SECOND = 9;
    
private:
    string name;
    vector<Card> hand_one;
    vector<Card> hand_two;
    int hand_one_size = 0;
    int hand_two_size = 0;
    int wins = 0;
    
};

Warrior * Warrior_factory(const string &name_in, const string &type_in) {
    
    if (type_in == "Bot") {
        return new Bot(name_in);
    }
    else if (type_in == "Real") {
        return new Real(name_in);
    }
    else {
        cout << "Error: Invalid Warrior Type -- Generating Bot Warrior" << endl;
        return new Bot("BOT");
    }
    
}

std::ostream & operator<<(std::ostream &os, const Warrior &w) {
    os << w.get_name();
    return os;
}
