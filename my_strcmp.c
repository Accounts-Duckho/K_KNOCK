#include <stdio.h>
#include <string.h>
int my_cmp(char *s1, char *s2) {
	printf("%d", strchr(s1, '\0')-s1);
	do {
		s1++;
		s2++;
		// 아래와 같은 상황일 경우에 대한 대처
		// 더 좋은 방안을 찾고 있습니다..
		if(*s1 == '\0' && *(s1+1)=='\0' )
			return *s1-*s2;
	} while(*s1 == *s2);
	return *s1-*s2;
}		
int main(void) {
	printf("%d", my_cmp("abc\0de", "손나은"));
	printf("%d", strcmp("\0", ""));
	return 0;
}
	
