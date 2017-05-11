#include "pokemon.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef __linux__
	#include <unistd.h>
#elif defined(_WIN32) || defined(_WIN64)
	#include <io.h>
	#include <windows.h>
	#define sleep(t) Sleep(1000*t)
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
		printf("%*s1. 새로 시작하기	2. 이어하기\n", 8,"");
		unsigned int newORload;
		do {
			printf(">> ");
			scanf("%u", &newORload);
		} while(newORload>2 || newORload<1);

		if(newORload==2) {
			loadData(user);
			mainMenu(user);
			return;
		}
	}
		makeFrame;
		printf("%*s플레이어 이름을 6자 이내로 입력해 주세요.\n", 4, "");
		do {
			printf(">> ");
			scanf("%s", user->name);
		} while(strlen(user->name)>18 || strlen(user->name)<=0);
	
		makeFrame;
		printf("%*s포켓몬 타입을 선택해주세요.\n\n", 12, "");
		printf("%*s1. 불 타입, 2. 풀 타입, 3. 물타입\n", 8, "");
		unsigned int sel_type;
		do {
			printf(">> ");
			scanf("%u", &sel_type);
		} while(sel_type>3 || sel_type<1);
		user->my_pokemon[0]=malloc(sizeof(Pokemon));
		user->my_pokemon[0]=create(sel_type);
		PokemonInfo(user->my_pokemon[0]);
		makeFrame;
		printf("%*s포켓몬의 이름을 지어주시겠습니까? ( Y or N )\n", 3,"");
		char sel_naming;
		do {
			printf(">> ");
			while(getchar() != '\n');
			scanf("%c", &sel_naming);
		} while( ( sel_naming!='Y' && sel_naming!='y' ) 
				&& ( sel_naming!='N' && sel_naming!='n' ) );
		if(sel_naming=='Y' || sel_naming=='y') {
			makeFrame;
			printf("%*s%7s의 닉네임을 지어주세요.\n", 10, "",user->my_pokemon[0]->name);
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
	printf("%*s%12s씨 여행을 시작하시겠습니까?\n", 5, "", user->name);
	PokemonInfo(user->my_pokemon[0]);
	printf("%*s1. 네 2. 아니요 3.자고가기( 포켓몬 체력회복 )\n", 3, "");
	unsigned int tripORcare;
	do {
		printf(">> ");
		scanf("%u", &tripORcare);
	} while(tripORcare>3 || tripORcare<1);
	switch(tripORcare) {
		case 1:
			tripCity(user, "제주시");
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
		printf("%*s(이름)  %s(%s)\n", 8, "", pokemon->nickName, pokemon->name);
	else
		printf("%*s(이름)  %s\n", 8, "", pokemon->name);
	switch(pokemon->type) {
		case 1:
			printf("%*s(타입)  불꽃\n", 8, "");
			break;
		case 2:
			printf("%*s(타입)  풀\n", 8, "");
			break;
		case 3:
			printf("%*s(타입)  물\n", 8, "");
			break;
		default:
			printf("%*s(타입)  알수없음\n", 8, "");
	}
	printf("%*s(공격력) %u\n", 7, "", pokemon->cur_atk);
	printf("%*s(체력)  %d/%u\n", 8, "", pokemon->cur_hp, pokemon->default_hp);
	makeFrame;
}
void tripCity(User* user, char* cityName) {
	blankOut;
	makeFrame;
	printf("%*s%s\n", 21, "", cityName);
	makeFrame;
	printf("%*s지니고 있는 포켓몬 수 : %d/6\n", 12, "", user->numOfPokemon);
	makeFrame;
	printf("%*s여행을 중단하시겠습니까? ( Y or N )\n", 8, "");
	char wannaExit;
	do {
		printf(">> ");
		while(getchar() != '\n');
		scanf("%c", &wannaExit);
	} while(( wannaExit!='Y' && wannaExit!='y' ) 
				&& ( wannaExit!='N' && wannaExit!='n' ));
	if(wannaExit=='Y' || wannaExit=='y') {
		saveData(user);
		exit(0);
	}
	makeFrame;
	printf(" 포켓몬들의 체력을 회복시키시겠습니까? ( Y or N )\n");
	char wannaHeal;
	do {
		printf(">> ");
		while(getchar() != '\n');
		scanf("%c", &wannaHeal);
	} while(( wannaHeal!='Y' && wannaHeal!='y' ) 
				&& ( wannaHeal!='N' && wannaHeal!='n' ));
	if(wannaHeal=='Y' || wannaHeal=='y')
		healPokemon(user, user->numOfPokemon);
	makeFrame;
	printf("%*s현재 상태를 저장하시겠습니까? ( Y or N )\n", 5, "");
	char wannaSave;
	do {
		printf(">> ");
		while(getchar() != '\n');
		scanf("%c", &wannaSave);
	} while(( wannaSave!='Y' && wannaSave!='y' ) 
				&& ( wannaSave!='N' && wannaSave!='n' ));
	if(wannaSave=='Y' || wannaSave=='y') saveData(user);

	if(wannaExit=='N' || wannaExit=='n') {
		makeFrame;
		printf("%*s길을 걷는중...\n", 18, "");
		makeFrame;
		sleep(3);
		battle(user, NULL);
	}
}	
void battle(User* user, Pokemon* wildPokemon) {
	static int cp=0; // current Pokemon index
	if(user->my_pokemon[0]->cur_hp==user->my_pokemon[0]->default_hp) cp=0;
	blankOut;
	makeFrame;
	if(wildPokemon==NULL) {
		wildPokemon=create(0);
		printf("%*s야생의 %s 출현!\n", 14,"", wildPokemon->name);
		makeFrame;
		if(strcmp(user->my_pokemon[cp]->nickName, "NULL"))
			printf(" %s :\t가라! %s(%s)\n", user->name, user->my_pokemon[cp]->nickName, user->my_pokemon[cp]->name);
		else
			printf(" %s :\t가라! %s\n", user->name, user->my_pokemon[cp]->name);
		makeFrame;
	}
	printf("%*s(야생) %s ", 25, "", wildPokemon->name);
	switch(wildPokemon->type) {
		case 1: printf("[불꽃]\n"); 
			break;
		case 2: printf("[풀]\n");
			break;
		case 3: printf("[물]\n");
			break;
		default:
			printf("[X]\n");
			break;
	}
	printf("\n");
	printf("%*s|HP| %4d / %-4u\n", 26, "", wildPokemon->cur_hp, wildPokemon->default_hp);
	printf("\n\n%*svs\n\n\n", 24, "");
	printf("%*s(%s) %s ", 2, "", user->name, user->my_pokemon[cp]->name);
	switch(user->my_pokemon[cp]->type) {
		case 1: printf("[불꽃]\n"); 
			break;
		case 2: printf("[풀]\n");
			break;
		case 3: printf("[물]\n");
			break;
		default:
			printf("[X]\n");
			break;
	}
	printf("\n");
	printf("%*s|HP| %4d / %-4u\n", 3, "", user->my_pokemon[cp]->cur_hp, user->my_pokemon[cp]->default_hp);
	makeFrame;
	printf("%*s1. 공격    2.도망치기    3.잡기\n", 9, "");
	unsigned int choice;
	do {
		printf(">> ");
		scanf("%u", &choice);
	} while(choice>3 || choice<1);
	switch(choice) {
		case 1:
			makeFrame;
			damage_process(wildPokemon, user->my_pokemon[cp]);
			if(wildPokemon->cur_hp<=0) {
				makeFrame;
				printf("%*s%s 기절\n", 16, "",  wildPokemon->name);
				free(wildPokemon);
				makeFrame;
				sleep(2);
				tripCity(user, "서귀포시");
				return;
			}
			damage_process(user->my_pokemon[cp], wildPokemon);
			if(user->my_pokemon[cp]->cur_hp<=0) {
				makeFrame;
				printf("%*s%s 기절\n", 16, "",  user->my_pokemon[cp]->name);
				makeFrame;
				if(user->numOfPokemon>=2 && cp < user->numOfPokemon-1) {
					printf("%*s다음 포켓몬을 내보내시겠습니까? (Y or N)\n", 5, "");
					char sel_next;
					do {
						printf(">> ");
						while(getchar() != '\n');
						scanf("%c", &sel_next);
					} while( ( sel_next!='Y' && sel_next!='y' ) 
						&& ( sel_next!='N' && sel_next!='n' ) );
					if(sel_next=='Y' || sel_next=='y') {
						++cp;
						battle(user, wildPokemon);
						return;
					}
				}
				healPokemon(user, user->numOfPokemon);
				cp=0;
				makeFrame;
				printf("%*s근처 포켓몬 센터에서 체력을 회복시켰다.\n", 5, "");
				makeFrame;
				free(wildPokemon);
				sleep(3);
				tripCity(user, "서귀포시");
				return;
			}
			makeFrame;
			sleep(1);
			battle(user, wildPokemon);
			break;
		case 2:
			if(rand()%2) {
				printf("%*s성공적으로 도망쳤다.\n", 15, "");
				free(wildPokemon);
				sleep(2);
				tripCity(user, "인천광역시");
				return;
			}	
			else { 
				printf("%*s%s\n", 15,"","도망치는데 실패했다.");
				makeFrame;
				damage_process(user->my_pokemon[cp], wildPokemon);
				makeFrame;
				if(user->my_pokemon[cp]->cur_hp<=0) {
					printf("%*s%s 기절\n", 16, "",  user->my_pokemon[cp]->name);
					makeFrame;
					if(user->numOfPokemon>=2 && cp < user->numOfPokemon-1) {
						printf("%*s다음 포켓몬을 내보내시겠습니까? (Y or N)\n", 5, "");
						char sel_next;
						do {
							printf(">> ");
							while(getchar() != '\n');
							scanf("%c", &sel_next);
						} while( ( sel_next!='Y' && sel_next!='y' ) 
							&& ( sel_next!='N' && sel_next!='n' ) );
						if(sel_next=='Y' || sel_next=='y') {
							++cp;
							battle(user, wildPokemon);
							return;
						}
					}
					healPokemon(user, user->numOfPokemon);
					cp=0;
					makeFrame;
					printf("%*s근처 포켓몬 센터에서 체력을 회복시켰다.\n", 5, "");
					makeFrame;
					free(wildPokemon);
					sleep(3);
					tripCity(user, "서귀포시");
					return;
				}
				sleep(2);
				battle(user, wildPokemon);
			}
			break;
		case 3:
			makeFrame;
			printf("%*s%s : 가랏 몬스터볼!\n", 11, "", user->name);
			makeFrame;
			if(catch_process(user, wildPokemon)) {
				makeFrame;
				damage_process(user->my_pokemon[cp], wildPokemon);
				makeFrame;
				if(user->my_pokemon[cp]->cur_hp<=0) {
					printf("%*s%s 기절\n", 16, "",  user->my_pokemon[cp]->name);
					makeFrame;
					if(user->numOfPokemon>=2 && cp < user->numOfPokemon-1) {
						printf("%*s다음 포켓몬을 내보내시겠습니까? (Y or N)\n", 5, "");
						char sel_next;
						do {
							printf(">> ");
							while(getchar() != '\n');
							scanf("%c", &sel_next);
						} while( ( sel_next!='Y' && sel_next!='y' ) 
							&& ( sel_next!='N' && sel_next!='n' ) );
						if(sel_next=='Y' || sel_next=='y') {
							++cp;
							battle(user, wildPokemon);
							return;
						}
					}
					healPokemon(user, user->numOfPokemon);
					cp=0;
					makeFrame;
					printf("%*s근처 포켓몬 센터에서 체력을 회복시켰다.\n", 5, "");
					makeFrame;
					free(wildPokemon);
					sleep(3);
					tripCity(user, "광주광역시");
					return;
				}
				sleep(2);
				battle(user, wildPokemon);
			}
			else {		
				blankOut;
				makeFrame;
				printf("%*s%s 획득!\n", 16, "", wildPokemon->name);
				user->my_pokemon[user->numOfPokemon]=malloc(sizeof(Pokemon));
				*(user->my_pokemon[user->numOfPokemon])=*wildPokemon;
				free(wildPokemon);
				makeFrame;
				printf("%*s포켓몬의 이름을 지어주시겠습니까? ( Y or N )\n", 3,"");
				char sel_naming;
				do {
					printf(">> ");
					while(getchar() != '\n');
					scanf("%c", &sel_naming);
				} while( ( sel_naming!='Y' && sel_naming!='y' ) 
					&& ( sel_naming!='N' && sel_naming!='n' ) );
				if(sel_naming=='Y' || sel_naming=='y') {
					makeFrame;
					printf("%*s%7s의 닉네임을 지어주세요.\n", 10, "",user->my_pokemon[user->numOfPokemon]->name);
					do {
						printf(">> ");
						scanf("%s", user->my_pokemon[user->numOfPokemon]->nickName);
					} while(strlen(user->my_pokemon[user->numOfPokemon]->nickName)>21 
						 || strlen(user->my_pokemon[user->numOfPokemon]->nickName)<=0);
				}
				++user->numOfPokemon;
				if(user->numOfPokemon==6) {
					blankOut;
					makeFrame;
					printf("  잡은 포켓몬들을 이박사에게 보내자! ( Y or N )\n");
					char sel_sending;
					do {
						printf(">> ");
						while(getchar() != '\n');
						scanf("%c", &sel_sending);
					} while( ( sel_sending!='Y' && sel_sending!='y' ) 
						&& ( sel_sending!='N' && sel_sending!='n' ) );
					if(sel_sending=='Y' || sel_sending=='y') {
						makeFrame;
						unsigned int i;
						for(i=1; i<user->numOfPokemon; i++) free(user->my_pokemon[i]);
						user->numOfPokemon=1;
						printf("%*s전송완료\n", 21, "");
						cp=0;
						printf("%*s이제 다시 여행을 떠나자!\n", 13, "");
						makeFrame;
						sleep(3);
						tripCity(user, "대전광역시");
						return;
					}
					else {
						makeFrame;
						printf("%*s좀 지치는걸.. 이젠 쉬어야겠어", 11, "");
						printf("%*sTHE END", 21, "");
						makeFrame;
						unsigned int i;
						for(i=0; i<user->numOfPokemon; i++) free(user->my_pokemon[i]);
						sleep(3);
						exit(0);
					}
				}
				sleep(3);
				tripCity(user, "울산광역시");
				return;
			}
		default:
			break;
	}
}
void damage_process(Pokemon* pokemon_1, Pokemon* pokemon_2) {
	unsigned int type_1p = pokemon_1->type;
	unsigned int type_2p = pokemon_2->type;
	unsigned int tmp=pokemon_1->cur_hp;
	pokemon_1->cur_hp-=pokemon_2->cur_atk;
	if(type_2p==1) {
		if(type_1p==2)
			pokemon_1->cur_hp-=((pokemon_2->cur_atk)/10);
		else if(type_1p==3)
			pokemon_1->cur_hp+=((pokemon_2->cur_atk)/10);
	}
	else if(type_2p==2) {
		if(type_1p==1)
			pokemon_1->cur_hp+=((pokemon_2->cur_atk)/10);
		else if(type_1p==3)
			pokemon_1->cur_hp-=((pokemon_2->cur_atk)/10);
	}
	else if(type_2p==3) {
		if(type_1p==1)
			pokemon_1->cur_hp-=((pokemon_2->cur_atk)/10);
		else if(type_1p==2)
			pokemon_1->cur_hp+=((pokemon_2->cur_atk)/10);
	}
	printf("%*s%s 체력 -%d 감소\n", 11, "", pokemon_1->name, tmp-(pokemon_1->cur_hp));
}
int catch_process(User* user, Pokemon* wildPokemon) {
	unsigned int randRange=0;
	if( wildPokemon->cur_hp >= (wildPokemon->default_hp/10)*3 ) {
		printf("%*s체력을 더 깍아주세요..\n", 14, "");
		return 1;
	}
	else {
		if( wildPokemon->cur_hp < wildPokemon->default_hp/10 ) randRange=10; // 90%
		else if( wildPokemon->cur_hp < (wildPokemon->default_hp/10) * 2 ) randRange=5; // 80%
		else randRange=4; // 75%
		
		if(rand()%randRange) return 0;
		else {
			printf("%*s포켓몬이 몬스터 볼을 빠져나왔다 !\n", 8, "");
			return 1;
		}
	}
	return 1;
}
