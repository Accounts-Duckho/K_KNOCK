#include <stdio.h>
int d(int n) {
	int tmp=n;
	do {
		tmp+=(n%10);
	} while(n/=10);
	return tmp;
}
int main(void) {
	int i;
	int sum=0, gen;
	int self[5000]={0,};
	for(i=0; i<5000; i++) {
		gen=d(i+1)-1;
		if(gen<5000) 
			self[gen]=1; 
	}
	for(i=0; i<5000; i++) 
		if(self[i]!=1)
			sum+=i+1;
	printf("%d\n", sum); 
	return 0;
}
