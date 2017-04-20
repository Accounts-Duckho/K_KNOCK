#include <stdio.h>
// line length = 50
#define makeFrame printf("==================================================\n")
#ifdef __linux
	#include <stdlib.h>
	#define blankOut system("clear")
#elif _WIN32 || _WIN64
	#include <windows.h>
	#define blankOut system("cls")
#endif

#define POKEDEX_MAX 5
#define POKELIST_MAX 6
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
