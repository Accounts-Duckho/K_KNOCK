#include "pokemon.h"

#include <stdio.h>
#ifndef __linux__
	#include <stdlib.h>
#endif
#include <time.h>
#include <string.h>

int main(void) {
	srand((unsigned)time(NULL));
	User* user = (User*)malloc(sizeof(User));
	
	blankOut;

	makeFrame;
	printf("%*s%s\n", 20,"", "포켓몬스터");
	printf("%*s%s\n", 14,"", "press any key to start");
	getchar();

	startMenu(user);
	return 0;
}
Pokemon* create(int type) {
	static char* pokemon_list[POKELIST_MAX];
	static int pokemon_type[POKELIST_MAX];
	static int isListLoaded=0;
	int n;
	if(!isListLoaded) {
		loadPokemonList(pokemon_list, pokemon_type);
		isListLoaded=1;
	}
	Pokemon* pokemon=(Pokemon *)malloc(sizeof(Pokemon));
	strcpy(pokemon->nickName,"NULL");
	if(type)
		n=2*(type-1)+rand()%2;
	else
		n=2*(rand()%3)+rand()%2;
	strcpy(pokemon->name, pokemon_list[n]);
	if(type) {
		pokemon->default_hp=500+rand()%501;
		pokemon->cur_hp=pokemon->default_hp;
		pokemon->default_atk=100+rand()%51;
		pokemon->cur_atk=pokemon->default_atk;
	} else {
		pokemon->default_hp=300+rand()%401;
		pokemon->cur_hp=pokemon->default_hp;
		pokemon->default_atk=100+rand()%101;
		pokemon->cur_atk=pokemon->default_atk;
	}
	if(type)
		pokemon->type=type;
	else
		pokemon->type=pokemon_type[n];
	return pokemon;
}
void healPokemon(User* user, int target) {
	int i;
	if(target==user->numOfPokemon) {
		for(i=0; i<user->numOfPokemon; i++)
			user->my_pokemon[i]->cur_hp=user->my_pokemon[i]->default_hp;
		return;
	}
	user->my_pokemon[target]->cur_hp = user->my_pokemon[target]->default_hp;
}

