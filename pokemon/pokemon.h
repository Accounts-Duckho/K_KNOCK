#include <stdio.h>
// line length = 50
#define makeFrame printf("==================================================\n")
#ifdef __linux__
	#include <stdlib.h>
	#define blankOut system("clear")
#elif defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
	#define blankOut system("cls")
#endif

#define KEY 56
#define POKELIST_MAX 6
struct Pokemon {	
	char name[22];
	char nickName[22];
	int type; // 1: 불, 2: 풀, 3: 물

	int default_hp;
	int default_atk;
	int cur_hp;	
	int cur_atk;
};

typedef struct Pokemon Pokemon;

struct User {
	char name[19];
	Pokemon *my_pokemon[6];
	int numOfPokemon;
};

typedef struct User User;

void startMenu(User* user);
void mainMenu(User* user);
void PokemonInfo(Pokemon* pokemon);
void meetPokemon(User* user, Pokemon* wildPokemon);
Pokemon* create(int type);
void healPokemon(User* user, int target);
void loadPokemonList(char* pokemon_list[], int pokemon_type[]);
void saveData(User* user);
void loadData(User* user);
void encrypt(char* str);
void decrypt(char* str);
