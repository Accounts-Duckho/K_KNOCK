#include <stdio.h>
int main(void) {
    int choice, size;
    int i, j, k;
    printf(" 출력 방식을 선택하세요.\n");
    printf(" 1. 오른쪽 아래로 점점 증가\n");
    printf(" 2. 왼쪽 아래로 점점 감소\n");
    printf(" 3. 오른쪽 아래로 점점 감소\n");
    printf(" 4. 왼쪽 아래로 점점 증가\n");
    printf(" : ");
    scanf("%d", &choice);
    printf(" 크기를 입력 : ");
    scanf("%d", &size);
    switch(choice) {
        case 1:
            // Mode 1
            for(i=1; i<=size; i++) {
                for(j=i; j!=0; j--)
                    printf("%c", '*');
                printf("\n");
            }
            break;
        case 2:
            // Mode 2   
            for(i=size; i!=0; i--) {
                for(j=i; j!=0; j--)
                    printf("%c", '*');
                printf("\n");
            }
            break;
        case 3:
            // Mode 3
            for(i=1; i<=size; i++) {
                for(k=0; k<i; k++)
                    printf(" ");
                k--; // k가 증가후 값이 비교되는 방식이라서.. 

                for(j=size-k; j!=0; j--)
                    printf("%c", '*');
                printf("\n");
            }
            break;

        case 4:
            // Mode 4           
            for(i=size; i!=0; i--) {
                for(k=0; k<i; k++)
                    printf(" ");
                k--; // k가 증가후 값이 비교되는 방식이라서.. 

                for(j=size-k; j!=0; j--)
                    printf("%c", '*');
                printf("\n");
            }
            break;

        default:
            printf("입력값 오류\n");
            break;
    }
    return 0;
}
