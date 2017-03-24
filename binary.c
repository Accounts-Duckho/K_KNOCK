#include <stdio.h>
int main(void) {
    int input;
    int choice;
    int num, i, j, n=0;
    printf(" 수 변환\n");
    printf(" 1. 2진수\n");
    printf(" 2. 8진수\n");
    printf(" 3. 16진수\n");
    printf(" 선택 : ");
    scanf("%d", &choice);

    printf(" 값 입력 : ");
    scanf("%d", &input);
    switch(choice) {
        case 1:
            // find closest 2^n
            for(i=input; i>=2; i/=2)
                n++;

            printf(" 변환결과 : ");

            // translating...
            for(i=n; i>=0; i--) {
                // get 2^n
                num=1;
                for(j=i; j!=0; j--)
                    num*=2;

                if(input>=num) {
                    printf("1");
                    input-=num;
                }
                else
                    printf("0");
            }
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