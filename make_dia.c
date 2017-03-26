#include <stdio.h>
int main(void) {
    int choice;
    int size;
    int isOdd;
    int i, j, line, comp;

    printf(" 출력 방식 선택\n");
    printf(" 1. *로 직접 출력\n");
    printf(" 2. 공백으로 간접 출력\n");
    printf(" : ");
    scanf("%d", &choice);

    printf(" 크기 입력 : ");
    scanf("%d", &size);
    //&연산은 둘다 1이면 1 
    isOdd=(size&1);

    switch(choice) {
        case 1:
            i = (isOdd) ? 1 : 2; // 초기 값
            int len = (isOdd) ? size : size-1;
            // *의 개수가 감소하기 시작하는 부분
            comp = (isOdd) ? (size+1)/2 : size/2;

            for(line=1; line<=len; line++) {
                printf("%*s", (size-i)/2, "");
                for(j=i; j>0; j--)
                    printf("*");
                printf("\n");

                if(line<comp) i+=2;
                else i-=2;
            }
            break;

        case 2:
            // 문자 + 공백 + 문자 
            i = (isOdd) ? 1 : 2;
            // 양끝은 제외하고 중간만 본다.
            int middle = size-2;

            comp = (isOdd) ? (middle+1)/2 : middle/2;
            for(j=size; j>0; j--)
                printf("*");
            printf("\n");
            for(line=1;line<=middle;line++) {
                for(j=1; j<=size; j++) {
                    if(j<=(size-i)/2) printf("*");
                    else if(j<=(size+i)/2) printf(" ");
                    else printf("*");
                }
                printf("\n");
                if(line<comp) i+=2;
                else i-=2;
                }
            if(isOdd) { // 짝수일떈 맨 밑줄이 무의미 
                for(j=size; j>0; j--)
                    printf("*");
                printf("\n");
            }
            break;
        default:
            printf("입력값 오류\n");
            break;
    }
    return 0;
}
