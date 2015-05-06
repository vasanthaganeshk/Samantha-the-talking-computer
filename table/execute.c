#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define and &&
#define or ||

main(){
	char input[100],output[200], ret_stmt[100];

	char str[10];
	int no_of_words = 1;
	FILE *fp, *fp1;
	int i = 0, j = 0, k = 0;

	int a = 0; int b = 0;
	
	while( (strcasecmp(input, "bye") != 0) && (strcasecmp(input, "bye samantha") != 0) ){
		fp = fopen("input.txt", "w");
		printf(">>>");
		scanf(" %[^\n]s", input);

		for(i = 0; i<strlen(input); i++){
			if(input[i] == ' '){
				no_of_words++;
			}
		}

		fprintf(fp, "%s\n", input);
		fclose(fp);
		system("./test1 <input.txt >output.txt");
		
		fp1 = fopen("output.txt", "r");

		k = 0;
		sprintf(ret_stmt," ");
		for(j = 0; fgets(output, 80, fp1)!=NULL; j++){
			sscanf(output, "rowid=%d columnid=%d", &a, &b);
			sprintf(str, "%d %d#", a, b);
			strcat(ret_stmt, str);
		}
		printf("%s\n", ret_stmt);
		fclose(fp1);
	}
}