CC = gcc
CFLAGS = -std=c17 -pedantic -Wall -g3 -fsanitize=address
INC = -I./include
OBJ = $(SRC:%.c=%.o)
SRC = src/pomme.c src/serpent.c src/jeu.c src/graphique.c src/main.c

all: $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o snake -lncurses

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

clean:
	rm -f *.o

fclean: clean
	rm -f test

re: fclean all