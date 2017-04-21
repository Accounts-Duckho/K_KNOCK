#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pokemon.h"
#ifdef __linux
	#include <unistd.h>
#elif _WIN32 || _WIN64
	#include <io.h>
#endif
int main(void) {
	int i;
	int newORload=0;
	srand((unsigned)time(NULL));
	User* user=(User*)malloc(sizeof(User));
	for(i=0; i<POKEDEX_MAX; i++)
		user->my_pokemon[i]=(Pokemon*)malloc(sizeof(Pokemon));
	makeFrame;
	printf("%*s%s\n", 20,"", "포켓몬스터");
	printf("%*s%s\n", 14,"", "press any key to start");
	getchar();
	
	blankOut;
#ifdef __linux
	if(access("./save_data", F_OK)==0) {
#elif _WIN32 || _WIN64
	if(access("./save_data", 0)==0) {
#endif
		makeFrame;
		printf("%*s%s\n", 9,"", "1. 새로 시작하기	2. 이어하기");
		do {
			printf(">> ");
			scanf("%d", &newORload);
		} while(newORload>2 || newORload<1);
		
		if(newORload==2) loadData(user);
	}
		if(newORload!=2) {	
			int sel_type;
			makeFrame;
			printf("%*s%s\n", 10, "", "어느 포켓몬을 고르시겠습니까?");
			printf("%*s%s\n", 8, "", "1. 불 타입, 2. 풀 타입, 3. 물타입");
			do {
				printf(">> ");
				scanf("%d", &sel_type);
			} while(sel_type>3 || sel_type<1);
			user->my_pokemon[0]=create(&sel_type);
		}
		for(i=0; i < user->numOfPokemon; i++)
			printf("%s | %d | %d / %d | %d\n",
					user->my_pokemon[i]->name, user->my_pokemon[i]->type,
					user->my_pokemon[i]->cur_hp, user->my_pokemon[i]->max_hp,
					user->my_pokemon[i]->atk);
	return 0;
}
Pokemon* create(int *type) {
	static FILE *pokemon_list_p;
	static char* pokemon_list[POKELIST_MAX];
	static int pokemon_type[POKELIST_MAX];
	int n;
	if(pokemon_list_p==NULL) {
		if((pokemon_list_p=fopen("pokemon_list", "r"))==NULL) {
			printf("pokemon_list 파일이 없습니다.\n");
			exit(1);
		}
		fscanf(pokemon_list_p, "%*[^\n]\n");
		int i;
		for(i=0; i<POKELIST_MAX; i++) {
			pokemon_list[i]=(char *)malloc(sizeof(char));
			fscanf(pokemon_list_p, "%d|%s\n", pokemon_type+i, pokemon_list[i]);
		}
	}
	Pokemon* pokemon=(Pokemon *)malloc(sizeof(Pokemon));
	if(type!=NULL)
		n=2*(*type-1)+rand()%2;
	else
		n=2*(rand()%3)+rand()%2;
	strcpy(pokemon->name, pokemon_list[n]);
	pokemon->max_hp=500+rand()%501;
	pokemon->cur_hp=pokemon->max_hp;
	pokemon->atk=100+rand()%51;
	if(type==NULL)
		pokemon->type=pokemon_type[n];
	else
		pokemon->type=*type;	
	return pokemon;
}

void loadData(User* user) {
	FILE *save_data;
	int i;
	if((save_data=fopen("save_data", "r"))==NULL) {
		printf("save_data 파일이 없습니다.\n");
		exit(1);
	}
	fscanf(save_data, "%d\n", &user->numOfPokemon);
	// Pokedex Load
	for(i=0; i < user->numOfPokemon ; i++)
		fscanf(save_data, "%s | %d | %d / %d | %d\n",
				user->my_pokemon[i]->name, &user->my_pokemon[i]->type,
				&user->my_pokemon[i]->cur_hp, &user->my_pokemon[i]->max_hp,
				&user->my_pokemon[i]->atk);
}
