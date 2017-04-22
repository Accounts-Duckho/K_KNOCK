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

#define POKEDEX_MAX 6
#define POKETYPE_MAX 3
#define POKELIST_MAX 6
struct Pokemon {	
	char name[20];
	int type; // 1: 불, 2: 풀, 3: 물
	int cur_hp;	
	int max_hp;
	int atk;
};
typedef struct Pokemon Pokemon;

struct User {
	Pokemon *my_pokemon[6];
	int numOfPokemon;
	int poketball;
};
typedef struct User User;

Pokemon* create(int type);
void mainMenu(User* user);
void PokemonInfo(Pokemon* pokemon);
void meetPokemon(User* user, Pokemon* wildPokemon);
void healPokemon(User* user, int target);
void saveData(User* user);
void loadData(User* user);
