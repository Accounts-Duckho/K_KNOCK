#include <stdio.h>
#include <stdlib.h>

// line length = 50
#define makeFrame printf("==================================================\n")
#define blankOut system("clear")

struct Pokemon {	
	char name[20];
	int type; // 1: 불, 2: 풀, 3: 물
	int hp;
	int atk;
};
typedef struct Pokemon Pokemon;

struct User {
	Pokemon *start_pokemon;
	Pokemon pokedex[5];	
	int pokeball;
};
typedef struct User User;

Pokemon* create(int *type);
