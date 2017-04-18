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
	user->start_pokemon=create(sel_type);
	printf("%s\n", user->start_pokemon->name);
	return 0;
}

Pokemon* create(int type) {
	// 불꽃 타입 2 , 풀 타입 2, 물 타입 2로 저장시킨다.
	const char *pokemon_list[6]=
		{"불꽃숭이", "브케인", "치코리타", "모부기", "꼬부기", "브이젤"};
	Pokemon* pokemon=(Pokemon *)malloc(sizeof(Pokemon));
	
	int n=2*(type-1)+rand()%2;
	strcpy(pokemon->name, pokemon_list[n]);
	pokemon->hp=500+rand()%501;
	pokemon->atk=100+rand()%51;
	
	return pokemon;
}
