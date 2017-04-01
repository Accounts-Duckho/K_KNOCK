  1 #include <stdio.h>
  2 #define YEAR_START 0 // 1월 1일이 일요일
  3 void showCalender(int mon) {
  4     int i;
  5     int days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  6     int day; // 요일
  7     int sum_rem=YEAR_START;
  8     // 비는 공백 계산
  9     for(i=0; i<mon-1; i++)  sum_rem=(sum_rem + (days[i]-28)) % 7;
 10 
 11     printf("%4d월\n", mon);
 12     printf("%s\n", "일 월 화 수 목 금 토" );
 13 
 14     for(i=0; i<sum_rem; i++)    printf("   ");
 15 
 16     for(day=1; day<=days[mon-1]; day++) {
 17         printf("%2d ", day);
 18         if((sum_rem+day)%7==0)  printf("\n");
 19     }
 20     if((sum_rem+day-1)%7!=0)    printf("\n"); // 마지막 day++를 없애려고 1을 뺀다.
 21 }
 22 int main(void) {
 23     int mon;
 24     printf(" 몇 월 달력을 보시겠어요?\n");
 25     do {
 26         printf(" 1~12 사이의 값으로 입력해주세요.\n");
 27         printf(" : ");
 28         scanf("%d", &mon);
 29     } while(mon<1 || mon>12);
 30     showCalender(mon);
 31     return 0;
 32 }
