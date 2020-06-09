# Mythic Cards

A command-line game in which two players battle with cards of mythical creatures, coded completely in the C++ language in under 6 hours. 
There are 2 players, and 0, 1, or 2 of them can be program-generated bots that make decisions like a real player would. 

## Relevant Topics

Object-Oriented Programming, with a focus on inheritance, polymorphism, and indirection with dynamic resources.
Attacks, Cards, and the Deck are all hierarchically-organized classes, and Warriors is defined as an interface from which the Bot and Real classes inherit (each representing the 2 types of players). Classes Attack, Card, and Deck were thoroughly tested with unit test cases, and the Player and Battle classes were tested through actual instances of the game. 

```bash
Warrior * Warrior_factory(const string &name_in, const string &type_in) {...} 
...
Attack Card::get_attack(string choice) {...} 
... 
std::vector<Card *> in_play;
```

## Gameplay and Rules

There are 18 cards of Mythical Creatures, each with an element and a form. 

```bash
Elements: Pyro, Aqua, Aero, Earth, Spectral, Gleam
Forms: Phoenix, Leviathan, Griffin, Behemoth, Djinn
```

There are four cards of the first four forms, and each of those four are the first four elements. There are two Djinn cards, with the elements Spectral and Gleam.

Of these cards, there are 6 'Origin Forms', which are cards with forms that match their type. These are:

```bash
Pyro Phoenix
Aqua Leviathan
Aero Griffin
Earth Behemoth
Spectral Djinn
Gleam Djinn
```

Each card has 100 health and two 'Attacks'. One is a Base Attack, which does 30 damage (reduces the opponent card's health). The other is an Ultra Attack, which does 70 damage. A card is alive as long as it's health is above 0. 

The entire game is played as a 'war' composed of a number of 'battles' that one player must win to win the war. This battles-to-win is determined by the players at the beginning of the game.
Each battle begins by dealing cards to the players, and then they face off in two main rounds. 

The 2 players are dealt 7 cards each, and four cards remain. Shuffling occurs before each time cards are dealt. Of the four cards that remain, the first one is known as the 'Aura Card'.

This 'Aura Card' creates an 'Aura' that spreads through the 'terrain' and creates a new prioritization among the cards. 

In round 1, each player deals a card, considering the aura and origin forms. Here are the priorities:

```bash
1. Origin Form with element matching Aura
2. Remaining Origin Forms
3. Cards with element matching Aura
4. All other cards
```
This is how a player chooses a card while playing (they will have two more cards in round 2).

```bash
Warrior Evan's turn.
Current cards:
Index 0 is Aqua Behemoth | Health: 100
Index 1 is Aero Griffin | Health: 100
Index 2 is Spectral Djinn | Health: 100
Index 3 is Pyro Griffin | Health: 100
Index 4 is Earth Griffin | Health: 100
Index 5 is Aero Phoenix | Health: 100
Index 6 is Gleam Djinn | Health: 100
Choose a card to play by its index: 
```

If the two cards that are dealt are equal in priority, players choose an Attack to use. Two Attacks that deal equal damage will damage both opponents. This is taken into account by real players and by any bot players the program controls. 

```bash
Gleam Djinn vs Earth Behemoth
Warrior Evan, please choose an attack to use.
Base Attack: Ethereal Ray
Ultra Attack: Ultra Divine Pulse
Choose an attack to use => enter either 'base' or 'ultra' to choose.
```

This continues until all the cards on one player's side are no longer alive. The player with cards remaining is the winner of round 1. They get to deal the remaining 4 cards between the 2 players.

```bash
Evan wins round one! 
Warrior Evan deals cards.
Warrior Evan gave Iris Aero Leviathan
Warrior Evan gave Iris Earth Phoenix

The aura disappeared from the terrain.

Round two begins!
```

The cards from round 1 that each player owns are restored, and they will additionally each have 2 of the 4 cards dealt after round 1 by the winner. This round is played the same way; both players deal cards and choose attacks until only one player has cards remaining. The priorities are different due to the lack of an 'Aura' in round 2. 

```bash
1. Origin Forms
2. All other cards
```

The winner of round 2 wins the battle and the number of battles won are updated. 

```bash
Iris wins the battle!

The battle is over!
Evan won 0 battles.
Iris won 2 battles.
```

After one player wins the number of battles needed to win the war, the game will end. 

```bash
The war is over!
Iris wins the war!
```

## Running the Project
The project is currently run completely on command-line, though I do plan to make it compatible on other platforms such as an iOS application. I also plan to expand the game to include more cards, have features such as special abilities, and have visuals.

To try the project, you can create a folder to store a local copy of this repository. In a command-line service such as terminal, open the folder containing all the files in this repository. 

Then, run the following commands to play the game in your terminal. 

```bash
$ g++ -Wall -Werror -pedantic --std=c++11 Mythic.cpp Card.cpp Warrior.cpp Attack.cpp Battle.cpp Deck.cpp -o mythic.exe 
```
followed by

```bash
$ ./mythic.exe
```

For any questions or collaboration opportunities, please email me at sisirpotluri2001@gmail.com

# Appendix

Here are all the Cards and their respective Attacks. 

```bash

Pyro Griffin
Inferno Claw
Ultra Inferno Assault

Pyro Phoenix
Magma Wing
Ultra Flaring Ascent

Pyro Leviathan
Searing Wave
Ultra Obsidian Trident

Pyro Behemoth
Tremor Blaze
Ultra Volcanic Rage

Aero Griffin
Twister Roar
Ultra Twister Tackle

Aero Phoenix
Hurricane Wing
Ultra Rapid Wind

Aero Leviathan
Cyclone Spout
Ultra Shredding Cyclone

Aero Behemoth
Wind Crusher
Ultra Gale Destruction

Aqua Griffin
Cerulean Wrath
Ultra Blue Tsunami

Aqua Phoenix
Blue Blaze
Ultra Freezing Flare

Aqua Leviathan
Tidal Oblivion
Ultra Ruinous Wave

Aqua Behemoth
Geyser Storm
Ultra Crashing Spout

Earth Griffin
Sand Crush
Ultra Sandy Rush

Earth Phoenix
Rocky Tornado
Ultra Stone Break

Earth Leviathan
Subzero Quake
Ultra Tidal Tremor

Earth Behemoth
Tectonic Terror
Ultra Wrathful Sierra

Spectral Djinn
Sinister Glare
Ultra Evil Nightmare

Gleam Djinn
Ethereal Ray
Ultra Divine Pulse

```
