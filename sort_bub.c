#include <stdio.h>
#include <stdlib.h>
int main(void) {
	FILE* input;
	FILE* output;
	if( ( input = fopen("input.txt", "r") ) == NULL ) {
		printf("input.txt 파일이 없습니다.\n");
		exit(1);
	}
	int tmp, count = 0;
	while(!feof(input)) {
		fscanf(input, "%d, ", &tmp); 
		count++;
	}
	int *arr = malloc(sizeof(int)*count);
	int index=0;
	rewind(input);
	while(!feof(input)) {
		fscanf(input, "%d, ", &arr[index]);
		index++;
	}
	fclose(input);
	// 내림차순
	int i,j;
	for(i=count-1; i>0; i--) {
		for(j=0; j<i; j++) {
			if(arr[j]<arr[j+1]) {
				tmp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=tmp;
			}
		}
	} 
	printf("test | ");
	for(i=0; i<count; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	if( ( output = fopen("output.txt", "w+") ) == NULL ) {
		printf("output.txt를 만드는데 실패하였습니다.\n");
		exit(1);
	}
	for(i=0; i<count; i++)
		fprintf(output, "%d, ", arr[i]);
	fclose(output);
	return 0;
}
