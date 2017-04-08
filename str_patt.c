#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int i, j, n, len;
	char *patt; // 패턴이 저장될 공간
	char **str;
	printf("문자열의 개수 : ");
	scanf("%d", &n);
	while(n>5000) {
		printf("5000이하의 수 입력!\n");
		printf("문자열의 개수 : ");
		scanf("%d", &n);
	}

	printf("문자열의 길이 : ");
	scanf("%d", &len);
	while(len>5000) {
		printf("5000이하의 수 입력!\n");
		printf("문자열의 길이 : ");
		scanf("%d", &len);
	}
	str=(char **)malloc(sizeof(char *)*n);
	for(i=0 ; i<n ; i++) {
		str[i]=(char *)malloc(sizeof(char)*(len+1));
		scanf("%s", str[i]);
	}
	patt=(char *)malloc(sizeof(char)*(len+1));
	for(i=0; i<len; i++) {
		patt[i]=str[0][i];
		for(j=1; j<n; j++) {
			if(patt[i]!=str[j][i]) {
				patt[i]='?';
				break;
			}
		}
	}

	patt[len]='\0';
	printf("%s\n", patt);

	free(patt);
	for(i=0; i<n; i++) free(str[i]);
	free(str);
	return 0;
}
