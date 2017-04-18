#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct Pocket {
	char name[20];
	char type[20];
	int age;
	int hp;
} Pocket;
char* pocket_name[6] = {"치코리타", "이상해씨", "파이리", "리자몽", "꼬부기", "야도란"};
char* pocket_type[6] = {"풀", "풀", "불꽃", "불꽃, 비행", "물", "물, 에스퍼"};
Pocket *create() {
	Pocket *mon=(Pocket *)malloc(sizeof(Pocket));
	int i=rand()%6;
	strcpy(mon->name, pocket_name[i]);
	strcpy(mon->type, pocket_type[i]);
	mon->age=rand()%101;
	mon->hp=mon->age*500;
	return mon;
}	
int main(void) {
	srand((unsigned)time());
	Pocket *pocket=create();
	printf("== 오늘의 포켓몬은 ? ==\n");
	printf("%s\n", pocket->name);
	printf("%s\n", pocket->type);
	printf("%d\n", pocket->age);
	printf("%d\n", pocket->hp);
	printf("== == == == == == == ==\n");
	return 0;
}
