CC = gcc
CFLAGS = -std=c17 -pedantic -Wall
IFLAGS = -I./include
OBJ = $(SRC:%.c=%.o)
SRC = src/pomme.c src/serpent.c src/jeu.c src/graphique.c src/main.c

all: $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) -lncurses -o snake

%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	rm -f *.o

fclean: clean
	rm -f test


## La déprime ##