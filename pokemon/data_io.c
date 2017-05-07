#include "pokemon.h"

#include <stdio.h>
#include <string.h>
void loadPokemonList(char* pokemon_list[], int pokemon_type[]) {
	FILE *pokemon_list_p;
	if(( pokemon_list_p=fopen("pokemon_list", "r") )==NULL) {
		printf("pokemon_list 파일이 없습니다.\n");
		exit(1);
	}
	fscanf(pokemon_list_p, "%*[^\n]\n");
	int i;

	for(i=0; i<POKELIST_MAX; i++) {
		pokemon_list[i]=malloc(sizeof(char *));
		fscanf(pokemon_list_p, "%d|%s\n", &pokemon_type[i], pokemon_list[i]);
	}

	fclose(pokemon_list_p);
}
void saveData(User* user) {
	// Save Level 0: start_poket
	FILE *save_data;
	int i;
	if((save_data=fopen("save_data", "w"))==NULL) {
		printf("save_data 파일이 없습니다.\n");
		exit(1);
	}
	encrypt(user->name);
	fprintf(save_data, "%s\n", user->name);
	fprintf(save_data, "%2d\n", user->numOfPokemon^KEY);
	for(i=0; i < user->numOfPokemon; i++) {
		encrypt(user->my_pokemon[i]->name);
		encrypt(user->my_pokemon[i]->nickName);
		fprintf(save_data, "%s %s %2d %4d %4d %3d %3d\n",
			user->my_pokemon[i]->name, user->my_pokemon[i]->nickName,
			user->my_pokemon[i]->type^KEY,
			user->my_pokemon[i]->cur_hp^KEY, user->my_pokemon[i]->default_hp^KEY,
			user->my_pokemon[i]->cur_atk^KEY, user->my_pokemon[i]->default_atk^KEY);
	}
	fclose(save_data);
}
void loadData(User* user) {
	FILE *save_data;
	unsigned int i;
	unsigned int len_uname, len_poname, len_nick;
	if((save_data=fopen("save_data", "r"))==NULL) {
		printf("save_data 파일이 없습니다.\n");
		exit(1);
	}
	fscanf(save_data, "%s\n", user->name);
	decrypt(user->name);
	fscanf(save_data, "%2d\n", &user->numOfPokemon);
	user->numOfPokemon^=KEY;
	for(i=0; i<user->numOfPokemon; i++)
		user->my_pokemon[i]=(Pokemon *)malloc(sizeof(Pokemon));
	// Pokedex Load
	for(i=0 ; i<user->numOfPokemon ; i++) {
		fscanf(save_data, "%s %s %2d %4d %4d %3d %3d\n",
			user->my_pokemon[i]->name, user->my_pokemon[i]->nickName,
			&user->my_pokemon[i]->type,
			&user->my_pokemon[i]->cur_hp, &user->my_pokemon[i]->default_hp,
			&user->my_pokemon[i]->cur_atk, &user->my_pokemon[i]->default_atk); 
		decrypt(user->my_pokemon[i]->name);
		decrypt(user->my_pokemon[i]->nickName);
		user->my_pokemon[i]->type^=KEY;
		user->my_pokemon[i]->cur_hp^=KEY;
		user->my_pokemon[i]->default_hp^=KEY;
		user->my_pokemon[i]->cur_atk^=KEY;
		user->my_pokemon[i]->default_atk^=KEY; 
	}
	fclose(save_data);
}
void encrypt(char *str) {
	unsigned int len = strlen(str);
	unsigned int i;
	for(i=0 ; i<len; i++) str[i]^=KEY;
}
void decrypt(char *enc_str) {
	unsigned int len = strlen(enc_str);
	unsigned int i;
	for(i=0 ; i<len; i++) enc_str[i]^=KEY;
}
