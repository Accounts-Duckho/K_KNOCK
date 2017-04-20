#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pokemon.h"

int main(void) {
	srand((unsigned)time(NULL));
	User* user=(User*)malloc(sizeof(User));
	user->start_pokemon=(Pokemon*)malloc(sizeof(Pokemon));
	makeFrame;
	printf("%*s%s\n", 20,"", "포켓몬스터");
	printf("%*s%s\n", 14,"", "press any key to start");
	getchar();
	
	blankOut;
	
	int sel_type;
	makeFrame;
	printf("%*s%s\n", 10, "", "어느 포켓몬을 고르시겠습니까?");
	printf("%*s%s\n", 8, "", "1. 불 타입, 2. 풀 타입, 3. 물타입");
   	do {
		printf(">> ");
		scanf("%d", &sel_type);
	} while(sel_type>3 || sel_type<1);
	user->start_pokemon->type=sel_type;
	user->start_pokemon=create(&sel_type);
	printf("%s %d\n", user->start_pokemon->name, user->start_pokemon->type);
	return 0;
}

Pokemon* create(int *type) {
	// 불꽃 타입 2 , 풀 타입 2, 물 타입 2로 저장시킨다.
	static FILE *pokemon_list_p;
	static char* pokemon_list[POKELIST_MAX];
	static int pokemon_type[POKELIST_MAX];
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
	int n=2*(*type-1)+rand()%2;
	strcpy(pokemon->name, pokemon_list[n]);
	pokemon->hp=500+rand()%501;
	pokemon->atk=100+rand()%51;
	if(type==NULL)
		*type=pokemon_type[n];
	pokemon->type=*type;	
	return pokemon;
}
