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
		printf("%*s%s\n", 8,"", "1. 새로 시작하기	2. 이어하기");
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
			// Init
			user->my_pokemon[0]=create(sel_type);
			user->numOfPokemon=1;
			user->poketball=5;
		}
		mainMenu(user);
	return 0;
}
Pokemon* create(int type) {
	static char* pokemon_list[POKELIST_MAX];
	static int pokemon_type[POKELIST_MAX];
	int n;
	static int listLoaded=0;
	if(!listLoaded) {
		FILE *pokemon_list_p;
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
		listLoaded=1;
		fclose(pokemon_list_p);
	}
	Pokemon* pokemon=(Pokemon *)malloc(sizeof(Pokemon));
	
	if(type)
		n=2*(type-1)+rand()%2;
	else
		n=2*(rand()%3)+rand()%2;
	
	strcpy(pokemon->name, pokemon_list[n]);
	if(type) {
		pokemon->max_hp=500+rand()%501;
		pokemon->cur_hp=pokemon->max_hp;
		pokemon->atk=100+rand()%51;
	} else {
		pokemon->max_hp=300+rand()%401;
		pokemon->cur_hp=pokemon->max_hp;
		pokemon->atk=100+rand()%101;
	}
	if(type)
		pokemon->type=type;
	else
		pokemon->type=pokemon_type[n];
	return pokemon;
}
void mainMenu(User* user) {
	int tripORcare;
	blankOut;
	makeFrame;
	printf("%*s%s\n\n", 14, "", "여행을 떠나시겠습니까?");
	printf("%*s%s\n", 3, "",
		"1. 네 2. 아니요 3.자고가기( 포켓몬 체력회복)");
	do {
		printf(">> ");
		scanf("%d", &tripORcare);
	} while(tripORcare>3 || tripORcare<1);
	switch(tripORcare) {
		case 1:
			meetPokemon(user, NULL);
			break;
		case 2:
			saveData(user);
			exit(0);
		case 3:
			healPokemon(user, 0);
			mainMenu(user);
			break;
		default:
			printf("입력값 에러\n");
			printf("아무키나 누르시면 종료됩니다.\n");
			getchar();
			exit(1);
	}
}
void PokemonInfo(Pokemon* pokemon) {
	makeFrame;
	printf("%*s%s%6s\n", 12, "", "  이름 : ", pokemon->name);
	switch(pokemon->type) {
		case 1:
			printf("%*s%s\n", 12, "", "  타입 : 불꽃");
			break;
		case 2:
			printf("%*s%s\n", 12, "", "  타입 : 풀");
			break;
		case 3:
			printf("%*s%s\n", 12, "", "  타입 : ");
			break;
		default:
			printf("%*s%s\n", 12, "", "  타입 : 알수없음");
	}
	printf("%*s%s%d/%d\n", 12,"", "  체력 : ", pokemon->cur_hp, pokemon->max_hp);
	printf("%*s%s%d\n", 12, "", "공격력 : ", pokemon->atk);
	makeFrame;
}
void healPokemon(User* user, int target) {
	int i;
	if(target==user->numOfPokemon) {
		for(i=0; i<user->numOfPokemon; i++)
			user->my_pokemon[i]->cur_hp=user->my_pokemon[i]->max_hp;
		return;
	}
	user->my_pokemon[target]->cur_hp = user->my_pokemon[target]->max_hp;
}
void meetPokemon(User* user, Pokemon* wildPokemon) {
	int choice;
	if(wildPokemon==NULL) wildPokemon=create(0);
	blankOut;
	makeFrame;
	printf("%*s%s\n\n", 12,"", "야생의 포켓몬이 나타났다.");
	PokemonInfo(wildPokemon);
	printf("%*s%s\n", 9, "", "1. 공격    2.도망치기    3.잡기");
	do {
		printf(">> ");
		scanf("%d", &choice);
	} while(choice>3 || choice<1);
	switch(choice) {
		case 1:
		case 2:
		case 3:
		default:
			break;
	}
}
void saveData(User* user) {
	// Save Level 0: start_poket
	FILE *save_data;
	int i;
	if((save_data=fopen("save_data", "w+"))==NULL) {
		printf("save_data 파일이 없습니다.\n");
		exit(0);
	}
	fprintf(save_data, "%d\n", user->poketball);
	fprintf(save_data, "%d\n", user->numOfPokemon);
	for(i=0; i < user->numOfPokemon; i++)
		fprintf(save_data, "%s | %d | %d / %d | %d\n",
			user->my_pokemon[i]->name, user->my_pokemon[i]->type,
			user->my_pokemon[i]->cur_hp, user->my_pokemon[i]->max_hp,
			user->my_pokemon[i]->atk);
	fclose(save_data);
}
void loadData(User* user) {
	char format[25];
	snprintf(format, sizeof(format),
		 "%%%ds | %%%dd | %%%dd / %%%dd | %%%dd\\n", 20, 1, 4, 4, 3);
	FILE *save_data;
	int i;
	if((save_data=fopen("save_data", "r"))==NULL) {
		printf("save_data 파일이 없습니다.\n");
		exit(1);
	}
	fscanf(save_data, "%d\n", &user->poketball);
	fscanf(save_data, "%d\n", &user->numOfPokemon);
	// Pokedex Load
	for(i=0; i < user->numOfPokemon ; i++)
		fscanf(save_data, format,
				user->my_pokemon[i]->name, &user->my_pokemon[i]->type,
				&user->my_pokemon[i]->cur_hp, &user->my_pokemon[i]->max_hp,
				&user->my_pokemon[i]->atk);
	fclose(save_data);
}
