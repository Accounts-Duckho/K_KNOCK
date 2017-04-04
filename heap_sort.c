#include <stdio.h>
int main(void) {
	int *num;
	int n;
	int i, j, index, upNode, tmp;
	scanf("%d", &n);
	num=(int *)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)	scanf("%d", num+i);
	for(index=0; index<n-1; index++) {
		for(i=1; i<n-index; i++) {
			if(i&1)		upNode=(i-1)/2;
			else		upNode=(i/2)-1;
			if(*(num+i) > *(num+upNode)) {
				tmp=*(num+i);
				*(num+i)=*(num+upNode);
				*(num+upNode)=tmp;
				i=0; // it will be 1
			}
		}
		tmp=*num;
		for(i=1; i<n-index; i++) *(num+i-1)=*(num+i);
		*(num+n-index-1)=tmp;
	}
	for(i=0; i<n; i++) printf("%d ", *(num+i));
	printf("\n");
	return 0;
}