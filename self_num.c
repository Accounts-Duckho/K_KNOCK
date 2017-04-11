#include <stdio.h>
int d(int n) {
	int tmp=n;
	do {
		tmp+=(n%10);
	} while(n/=10);
	return tmp;
}
int main(void) {
	int i, j;
	int sum, tmp;
	for(i=1; i<5000; i++) {
		tmp=d(i);
		printf("[%d] %d\n", i, tmp);
		for(j=tmp; j>i; j--) 
			if(tmp==d(j)) {
				tmp=0;
				break;
			}
		printf("[%d] %d\n", i, tmp);
	sum+=tmp;
	}
	printf("%d\n", sum); 
	return 0;
}
