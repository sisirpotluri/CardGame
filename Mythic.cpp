//
//  Mythic.cpp
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

int main () {
    
    int num_players = 0;
    
    string player1;
    string player1_type;
    string player2;
    string player2_type;
    
    int num_wars;
    
    cout << "How many players will play (up to 2)? The rest will be computer-generated bots." << endl;
    
    cin >> num_players;
    
    while(!(num_players == 0 || num_players == 1 || num_players == 2)) {
        cout << "A maximum of 2 players can play, please enter a valid number of players." << endl;
        cin >> num_players;
    }
    
    if (num_players == 0) {
        player1 = "BOT1";
        player1_type = "Bot";
        player2 = "BOT2";
        player2_type = "Bot";
    }
    
    else if (num_players == 1) {
        
        cout << "Please enter your name." << endl;
        cin >> player1;
        
        player1_type = "Real";
        player2 = "BOT";
        player2_type = "Bot";
        
    }
    else {
        
        cout << "Please enter one player's name." << endl;
        cin >> player1;
        
        cout << "Please enter the other player's name." << endl;
        cin >> player2;
        
        player1_type = "Real";
        
        player2_type = "Real";
        
    }
    
    cout << "How many battles must be won to decide the winner of the war?" << endl;
    
    cin >> num_wars;
    
    vector<string> data;
    
    data.push_back(player1);
    data.push_back(player1_type);
    data.push_back(player2);
    data.push_back(player2_type);
    
    Battle main_battle(data, num_wars);
    
    main_battle.play_game();
    
    return 0;
}
