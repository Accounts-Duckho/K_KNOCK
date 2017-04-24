#include <stdio.h>
int main(void) {
    int input;
    int choice;
    int num, i, j;
    int n=0;

    printf(" 수변환\n");
    printf(" 1. 2진수\n");
    printf(" 2. 8진수\n");
    printf(" 3. 16진수\n");
    printf(" 선택 : ");
    scanf("%d", &choice);

    printf(" 수 입력: ");
    scanf("%d", &input);

    switch(choice) {
        case 1:
            printf("변환결과 : ");
            if(input<2) {
                printf("%d\n", input);
                break;
            }
            // find closest 2^n
            for(i=input; i>=2; i/=2)
                n++;
            for(i=n; i>=0; i--) 
                printf("%d", input >> i & 0x01);
            printf("\n");
            break;

        case 2:
            printf(" 변환결과 : %#o\n", input);
            break;

        case 3:
            printf(" 변환결과 : %#x\n", input);
            break;

        default:
            printf(" 입력값 오류\n");
            break;
    }
    return 0;
}
