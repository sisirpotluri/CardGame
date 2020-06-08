CC=gcc
CFLAGS=-I.
DEPS = Battle.h Warrior.h Deck.h Attack.h Card.h
OBJ = Battle.cpp Warrior.cpp Deck.cpp Attack.h Card.cpp Mythic.cpp

%.o: %.c $(DEPS)
    $(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
    $(CC) -o $@ $^ $(CFLAGS)
