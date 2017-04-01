#include <stdio.h>
#define YEAR_START 0 // 1월 1일이 일요일
void showCalender(int mon) {
    int i;
    int days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day; // 요일
    int sum_rem=YEAR_START;
    // 비는 공백 계산
    for(i=0; i<mon-1; i++)  sum_rem=(sum_rem + (days[i]-28)) % 7;

    printf("%4d월\n", mon);
    printf("%s\n", "일 월 화 수 목 금 토" );

    for(i=0; i<sum_rem; i++)    printf("   ");

    for(day=1; day<=days[mon-1]; day++) {
        printf("%2d ", day);
        if((sum_rem+day)%7==0)  printf("\n");
    }
    if((sum_rem+day-1)%7!=0)    printf("\n"); // 마지막 day++를 없애려고 1을 뺀다.
}
int main(void) {
    int mon;
    printf(" 몇 월 달력을 보시겠어요?\n");
    do {
        printf(" 1~12 사이의 값으로 입력해주세요.\n");
        printf(" : ");
        scanf("%d", &mon);
    } while(mon<1 || mon>12);
    showCalender(mon);
    return 0;
}
