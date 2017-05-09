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
	// 오름차순
	int i,j, min, min_pt;
	for(i=0; i<count-1; i++) {
		min=arr[i];
		for(j=i+1; j<count; j++)
			if(arr[j]<min) {
				min=arr[j];
				min_pt=j;
			}
		tmp=arr[i];
		arr[i]=min;
		arr[min_pt]=tmp;
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
