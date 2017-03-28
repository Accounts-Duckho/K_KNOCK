#include <stdio.h>
int main(void) {
	int choice;
    int size;
    int isOdd;
    int i, j, line, comp;
	printf("별로 모양 만들기\n");
	printf(" 1: 모래시계 만들기, 2: 나비 만들기 ");
	printf(" : ");
	scanf("%d", &choice);
    printf(" 크기 입력 : ");
    scanf("%d", &size);
    // 마지막 비트와 비교
    isOdd=(size&1);
    int len = (isOdd) ? size : size-1;
	switch(choice) {
		case 1:
			// i 초기값
		    i = size;
            // *의 개수가 감소하기 시작하는 부분
            comp = (isOdd) ? (size+1)/2 : size/2;

            for(line=1; line<=len; line++) {
                printf("%*s", (size-i)/2, "");
                for(j=i; j>0; j--)
                    printf("*");
                printf("\n");

                if(line<comp) i-=2;
                else i+=2;
            }
			break;
		case 2:
            // i 초기값
            i =  size-2;
	    int len = (isOdd) ? size : size-1;
            comp = (isOdd) ? (size+1)/2 : size/2;
            for(line=1;line<=len;line++) {
                for(j=1; j<=size; j++) {
                    if(j<=(size-i)/2) printf("*");
                    else if(j<=(size+i)/2) printf(" ");
                    else printf("*");
                }
                printf("\n");
                if(line<comp) i-=2;
                else i+=2;
                }
			break;
		default:
			printf("입력값 에러\n");
			break;
	}
    return 0;
}
