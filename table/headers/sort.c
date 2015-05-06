#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main(){
	int i = 0;
	int j = 0;
	int k = 0;
	char *temp;
	int no_of_elements = 3;

	char c[3][7]={{"i"},{"love"},{"python"}};

	for(j = no_of_elements -1; j>=0; j--){
		k = 0;
		for(i = 1; i<=j; i++){
			if(strcmp(c[k], c[i]) < 0){
				k = i;
			}
		}

		temp = (char *)malloc(strlen(c[k]) + 1);
		strcpy(temp, c[k]);
		strcpy(c[k], c[j]);
		strcpy(c[j], temp);
		free(temp);
	}

	for(i = 0; i<no_of_elements; i++){
		printf("%s\n",c[i] );
	}
}