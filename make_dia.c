#include <stdio.h>
int main(void) {
    int choice, size, isOdd;
    int i, j, line, comp;
    printf(" 출력 방식 선택 \n");
    printf(" 1. 특수문자로 직접 출력\n");
    printf(" 2. 공백으로 간접 출력\n");
    printf(" : ");
    scanf("%d", &choice);

    printf(" 크기 입력 : ");
    scanf("%d", &size);
    isOdd=(size&1) ? 1 : 0;

    switch(choice) {
        case 1:

            i=(isOdd) ? 1 : 2;
            comp = (isOdd) ? (size+1)/2 : size/2;
            for(line=1; line<=size; line++) {
                if(i==0) break; // 짝수일때 생기는 마지막 한줄제거
                for(j=(size-i)/2; j!=0; j--)
                    printf(" ");
                for(j=i; j!=0; j--)
                    printf("%c", '*');
                printf("\n");
                if(line<comp)
                    i+=2;
                else
                    i-=2;
            }
            break;

        case 2:
            //  문자 + 공백 + 문자
            i=(isOdd) ? 1 : 2;
            int middle=size-2;
            comp = (isOdd) ? (middle+1)/2 : middle/2;

            for(j=size; j!=0; j--) // 양 끝은 어짜피 size와 동일한 길이
                printf("%c", '*');
            printf("\n");

            for(line=1; line<=middle; line++) {
                for(j=(size-i)/2; j!=0; j--)
                    printf("%c", '*');
                for(j=i; j!=0; j--)
                    printf(" ");
                for(j=(size-i)/2; j!=0; j--)
                    printf("%c", '*');
                printf("\n");
                if(line<comp)
                    i+=2;
                else
                    i-=2;
            }

            if(isOdd) { // 짝수일땐 맨 밑에 줄이 무의미
                for(j=size; j!=0; j--)
                    printf("%c", '*');
                printf("\n");
            }
            break;

        default:
            printf("입력값 오류");
            break;
    }
    return 0;
}
