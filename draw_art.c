#include <stdio.h>
#include <stdlib.h>
typedef struct ArrStruct {
	int **timewheel;
	int **nabi;
	int size_arr;
	} ArrStruct;

void create(ArrStruct *arr, int num);
void print(ArrStruct *arr);

int main(void) {
	ArrStruct *art;
	int num;
	printf("크기 입력 : ");
	scanf("%d", &num);
	create(art, num);
	print(art);

	// free
	if(!(num&1)) num--;
	while(num--) {
		free(art->timewheel[num]);
		free(art->nabi[num]);
	}
	free(art->timewheel);
	free(art->nabi);
    return 0;
}

void create(ArrStruct *arr, int num) {
    int i, j, line, mid;
	int len = (num&1) ? num : num-1;

	arr->timewheel=(int **)malloc(sizeof(int *) * len);
	for(i=0; i<len; i++) 
		arr->timewheel[i]=(int *)malloc(sizeof(int) * num);

	arr->nabi=(int **)malloc(sizeof(int *) * len);
	for(i=0; i<len; i++) 
		arr->nabi[i]=(int *)malloc(sizeof(int) * num);

	arr->size_arr=num;

	// 줄 번호가 0부터 시작
    mid = (len-1)/2;

// 모래시계
	i = num;
	for(line=0; line<len; line++) {
    	for(j=0; j<num; j++) {
        	if(j<(num-i)/2) 
				arr->timewheel[line][j]=0;
            else if(j<(num+i)/2) 
				arr->timewheel[line][j]=1;
            else 
				arr->timewheel[line][j]=0;
		}
        if(line<mid) i-=2;
        else i+=2;
	}

// 나비
	i =  num-2;
    for(line=0;line<len;line++) {
    	for(j=0; j<num; j++) {
        	if(j<(num-i)/2) 
				arr->nabi[line][j]=1;
            else if(j<(num+i)/2) 
				arr->nabi[line][j]=0;
            else 
				arr->nabi[line][j]=1;
		}
        if(line<mid) i-=2;
        else i+=2;
	}
}

void print(ArrStruct *arr) {
	int size=arr->size_arr;
	int i, j;
	int len=(size&1) ? size : size-1;

// 모래시계
	printf("== 모래시계  출력  ==\n");
	for(i=0; i<len; i++) {
		for(j=0; j<size; j++)
			printf("[%d]", arr->timewheel[i][j]);
		printf("\n");
	}
	printf("== == == === == == ==\n");

// 나비
	printf("== == 나비 출력 == ==\n");
	for(i=0; i<len; i++) {
		for(j=0; j<size; j++)
			printf("[%d]", arr->nabi[i][j]);
		printf("\n");
	}
	printf("== == == === == == ==\n");
}
