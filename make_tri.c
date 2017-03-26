#include <stdio.h>
int main(void) {
    int choice;
    int size;
    int i, j;

    printf(" 출력 방식을 선택하세요.\n");
    printf(" 1. 오른쪽 방향으로 점점 증가\n");
    printf(" 2. 왼쪽 방향으로 점점 감소\n");
    printf(" 3. 오른쪽 방향으로 점점 감소\n");
    printf(" 4. 왼쪽 방향으로 점점 증가\n");
    printf(" : ");
    scanf("%d", &choice);
    printf("크기를 입력 : ");
    scanf("%d", &size);

    switch(choice) {
        case 1:
            for(i=1; i<=size; i++) {
                for(j=i; j>0; j--)
                    printf("*");
                printf("\n");
            }
            break;

        case 2:
            for(i=size; i>0; i--) {
                for(j=i; j>0; j--)
                    printf("*");
                printf("\n");
            }
            break;

        case 3:
            for(i=size; i>0; i--) {
                for(j=size; j>0; j--) {
                    if(j>i) printf(" ");
                    else printf("*");
                }
                printf("\n");
            }
            break;

        case 4:
            for(i=size; i>0; i--) {
                printf("%*s", i-1, "");
                for(j=(size-i)+1; j>0; j--)
                    printf("*");
                printf("\n");
            }
            break;
    }
    return 0;
}
