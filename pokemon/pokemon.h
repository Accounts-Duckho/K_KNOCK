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
	char name[19];
	char nickName[22];
	unsigned int type; // 1: 불, 2: 풀, 3: 물

	unsigned int default_hp;
	unsigned int default_atk;
	int cur_hp;	
	unsigned int cur_atk;
};

typedef struct Pokemon Pokemon;

struct User {
	char name[19];
	Pokemon *my_pokemon[6];
	unsigned int numOfPokemon;
};

typedef struct User User;

void startMenu(User* user);
void mainMenu(User* user);
void PokemonInfo(Pokemon* pokemon);
void tripCity(User* user, char* cityName);
void battle(User* user, Pokemon* wildPokemon);
void damage_process(Pokemon* pokemon_1, Pokemon* pokemon_2);
int catch_process(User* user, Pokemon* wildPokemon);
Pokemon* create(unsigned int type);
void healPokemon(User* user, unsigned int target);
void loadPokemonList(char* pokemon_list[], unsigned int pokemon_type[]);
void saveData(User* user);
void loadData(User* user);
void encrypt(char* str);
void decrypt(char* str);
