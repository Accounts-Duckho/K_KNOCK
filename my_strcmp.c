#include <stdio.h>
int my_cmp(char *s1, char *s2) {
	do {
		s1++;
		s2++;
		if(*s1 == '\0')
			return *s1-*s2;
	} while(*s1 == *s2);
	return *s1-*s2;
}		
int main(void) {
	printf("%d", my_cmp("손나은", "손새은"));
	return 0;
}