#include <stdio.h>
#define YEAR_START 0 // 1월 1일이 일요일
int daysInMonth(int month) {
    switch(month) {
        case 2:
            return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void showCalender(int month) {
    int i;
    char* week[7]={"일", "월", "화", "수", "목", "금", "토"};
    int day=1;
    int start_month=YEAR_START;
    int end_month=daysInMonth(month);
    // 월
    printf("   %d월\n", month);
    // 요일
    for(i=0; i<7; i++)
        printf("%s ", week[i]);
    printf("\n");
    // 비는 공백 계산
    for(i=1; i<month; i++) {
        start_month+=(daysInMonth(i)-28);
        start_month%=7;
    }
    // 공백 먼저 출력
    for(i=0; i<start_month; i++)
        printf("   ");
    // 요일 출력 ( 개행 까지 )
    while(day<=end_month) {
        if(day<10)
            printf(" %d ", day);
        else
            printf("%d ", day);
        if((start_month+day)%7==0)
            printf("\n");
        day++;
    }
    /*
       7의 배수로 끝나면 개행 필요없음
       마지막에 day++가 실행되고 끝남
     */
    if((start_month+day-1)%7!=0)
        printf("\n");
}
int main(void) {
    int month;
    scanf("%d", &month);
    if(month>12 || month<1)
        printf("[입력값 오류] 1~12 사이의 값으로 입력해주세요.");
    showCalender(month);
    return 0;
}
