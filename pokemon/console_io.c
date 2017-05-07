#include "pokemon.h"

#include <stdio.h>
#include <string.h>
#ifdef __linux__
	#include <unistd.h>
#elif defined(_WIN32) || defined(_WIN64)
	#include <io.h>
	#include <windows.h>
#endif

void startMenu(User* user) {
	blankOut;
#ifdef __linux__
	if(access("./save_data", F_OK)==0) 
#elif defined(_WIN32) || defined(_WIN64)
	if(access("./save_data", 0)==0) 
#endif
	{
		makeFrame;
		printf("%*s%s\n", 8,"", "1. 새로 시작하기	2. 이어하기");
		int newORload;
		do {
			printf(">> ");
			scanf("%d", &newORload);
		} while(newORload>2 || newORload<1);

		if(newORload==2) {
			loadData(user);
			mainMenu(user);
			return;
		}
	}
		makeFrame;
		printf("%*s%s\n", 4, "", "플레이어 이름을 6자 이내로 입력해 주세요.");
		do {
			printf(">> ");
			scanf("%s", user->name);
		} while(strlen(user->name)>18 || strlen(user->name)<=0);
	
		makeFrame;
		printf("%*s%s\n", 10, "", "어느 포켓몬을 고르시겠습니까?");
		printf("%*s%s\n", 8, "", "1. 불 타입, 2. 풀 타입, 3. 물타입");
		int sel_type;
		do {
			printf(">> ");
			scanf("%d", &sel_type);
		} while(sel_type>3 || sel_type<1);
		user->my_pokemon[0]=malloc(sizeof(Pokemon));
		user->my_pokemon[0]=create(sel_type);
		PokemonInfo(user->my_pokemon[0]);
		makeFrame;
		printf("%*s%s\n", 3,"","포켓몬의 이름을 지어주시겠습니까? ( Y or N )");
		char sel_naming;
		do {
			printf(">> ");
			while(getchar() != '\n');
			scanf("%c", &sel_naming);
		} while( ( sel_naming!='Y' && sel_naming!='y' ) 
				&& ( sel_naming!='N' && sel_naming!='n' ) );
		if(sel_naming=='Y' || sel_naming=='y') {
			makeFrame;
			printf("%*s%7s%s\n", 10, "",user->my_pokemon[0]->name, "의 닉네임을 지어주세요.");
			do {
				printf(">> ");
				scanf("%s", user->my_pokemon[0]->nickName);
			} while(strlen(user->my_pokemon[0]->nickName)>21 
				 || strlen(user->my_pokemon[0]->nickName)<=0);
		}
		user->numOfPokemon=1;
		mainMenu(user);
}

void mainMenu(User* user) {
	blankOut;
	makeFrame;
	printf("%*s%7s%s\n\n", 10, "", user->name,"씨 여행을 떠나시겠습니까?");
	PokemonInfo(user->my_pokemon[0]);
	printf("%*s%s\n", 3, "",
		"1. 네 2. 아니요 3.자고가기( 포켓몬 체력회복)");
	int tripORcare;
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
	if(strcmp(pokemon->nickName,"NULL"))
		printf("%*s%s%7s(%s)\n", 12, "", "  이름 : ", pokemon->nickName, pokemon->name);
	else
		printf("%*s%s%7s\n", 12, "", "  이름 : ", pokemon->name);
	switch(pokemon->type) {
		case 1:
			printf("%*s%s\n", 12, "", "  타입 : 불꽃");
			break;
		case 2:
			printf("%*s%s\n", 12, "", "  타입 : 풀");
			break;
		case 3:
			printf("%*s%s\n", 12, "", "  타입 : 물");
			break;
		default:
			printf("%*s%s\n", 12, "", "  타입 : 알수없음");
	}
	printf("%*s%s%d/%d\n", 12,"", "  체력 : ", pokemon->cur_hp, pokemon->default_hp);
	printf("%*s%s%d\n", 12, "", "공격력 : ", pokemon->default_atk);
	makeFrame;
}
void meetPokemon(User* user, Pokemon* wildPokemon) {
	if(wildPokemon==NULL) {
		wildPokemon=create(0);
		blankOut;
		makeFrame;
		printf("%*s%s\n\n", 12,"", "야생의 포켓몬이 나타났다.");
		PokemonInfo(wildPokemon);
	}
	else makeFrame;
	printf("%*s%s\n", 9, "", "1. 공격    2.도망치기    3.잡기");
	int choice;
	do {
		printf(">> ");
		scanf("%d", &choice);
	} while(choice>3 || choice<1);
	switch(choice) {
		case 1:
			
		case 2:
			if(rand()%2) {
				printf("%*s%s\n", 15, "", "성공적으로 도망쳤다.");
				printf("%*s%s\n", 13, "", "하지만 여행은 계속된다.");
				sleep(2);
				meetPokemon(user, NULL);
			}	
			else { 
				printf("%*s%s\n", 15,"","도망치는데 실패했다.");
				meetPokemon(user, wildPokemon);
			}
			break;
		case 3:
		default:
			break;
	}
}
