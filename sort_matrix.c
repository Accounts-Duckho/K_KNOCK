#include <stdio.h>
#include <stdlib.h>
/* 사용한 정렬 : 선택 정렬
   기준을 잡고 기준과 이미 정해진
   수들을 제외한 수들중 최소 or 최대 값을 
   구해 기준과 바꾼다.
   그 작업을 반복하여 정렬시킨다. */
void inc_sort(int **num, int table_size);
void dec_sort(int **num, int table_size);
void reverse_sort(int **num, int table_size);
void ryle_sort(int **num, int n);

int main(void) {
    int n;
    int **num=NULL;
    int sort_choice;
    int i, j;

    printf("크기 입력\n");
    do {
        printf("3~10까지의 수만 써주세요.\n");
        scanf("%d", &n);
    } while(n<3 || n>10);

    // n개의 열을 할당
    num=(int**)malloc(sizeof(int*)*n);
    /* 연속적인 할당을 위해 */
    num[0]=(int *) malloc (sizeof(int)*n*n);

    for(i=1; i<n; i++)  num[i] = num[i-1]+n;

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("(%d, %d) : ", i, j);
            scanf("%d", &num[i][j]);
        }
    }
    printf(" [ 정렬 ]\n");
    printf(" 1. 오름차순\n");
    printf(" 2. 내림차순\n");
    printf(" 3. 역순\n");
    printf(" 4. ㄹ형정렬\n");
    printf(" [ 선택 ]\n");
    printf(" : ");
    scanf("%d", &sort_choice);

    switch(sort_choice) {
        case 1:
            inc_sort(num, n*n);     break;

        case 2:
            dec_sort(num, n*n);     break;

        case 3:
            reverse_sort(num, n);       break;

        case 4:
            ryle_sort(num, n);      break;

        default:
            printf("입력값 오류\n");
    }

    for(i=0; i<n*n; i++) {
        printf("[%2d]", *(*num+i));
        if((i+1)%n==0)  printf("\n");
    }

    free(num[0]);
    free(num);
    return 0;
}

void inc_sort(int **num, int table_size) {
    int i, j, temp;
    int pt, min;
    int min_pt;
    /* [0][N-1] 다음 [1][0] 이런 식으로
       연속적으로 할당 되있다.
     */
    for(pt=0; pt<table_size-1; pt++) {
        min=*(*num+pt);
        min_pt=pt;
        for(i=pt+1; i<table_size; i++) {
            if(*(*num+i)<min) {
                min=*(*num+i);
                min_pt=i;
            }
        }

        if(*(*num+min_pt) < *(*num+pt)) {
            temp=*(*num+pt);
            *(*num+pt)=min;
            *(*num+min_pt)=temp;
        }
    }
}
void dec_sort(int **num, int table_size) {
    int i, j, temp;
    int pt, max;
    int max_pt;

    for(pt=0; pt<table_size-1; pt++) {
        max=*(*num+pt);
        max_pt=pt;
        for(i=pt+1; i<table_size; i++) {
            if(*(*num+i)>max) {
                max=*(*num+i);
                max_pt=i;
            }
        }

        if(*(*num+max_pt) > *(*num+pt)) {
            temp=*(*num+pt);
            *(*num+pt)=max;
            *(*num+max_pt)=temp;
        }
    }
}
void reverse_sort(int **num, int n) {
    int i, temp;
    int table_size=n*n;
    int break_pt;
    if(n&1)     break_pt=(table_size-1)/2;
    else        break_pt=table_size/2;
    for(i=0; i<break_pt; i++) {
        temp=*(*num+i);
        *(*num+i)=*(*num+(table_size-1)-i);
        *(*num+(table_size-1)-i)=temp;
    }
}
void ryle_sort(int **num, int n) {
    int i, temp;
    int table_size=n*n;
    int pt, break_pt;
    int comp;
    // 일단 배열 전체적으로 정렬
    inc_sort(num, table_size);

    // 짝수 열마다 정렬방식을 바꿈
    for(pt=n; pt<table_size; pt+=2*n) {
        break_pt=pt;
        if(n&1)     break_pt+=(n-1)/2;
        else        break_pt+=n/2;
        for(i=pt; i<break_pt; i++) {
            temp=*(*num+i);
            *(*num+i)=*(*num+2*break_pt-i-((n+1)&1));
            *(*num+2*break_pt-i-((n+1)&1))=temp;
        }
    }
}
