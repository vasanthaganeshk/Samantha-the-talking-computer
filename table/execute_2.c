#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"headers/mapper2.h"

#define and &&
#define or ||

void insertingone(char *dup_ret_stmt, char *ret_stmt){
	int ret_val;

	sqlite3_stmt *stmt;
	sqlite3 *handle;
	char queries[100];
	ret_val = sqlite3_open("linking.sqlite3", &handle);

	if(ret_val){
		printf("failed\n");
	}
	sprintf(queries, " ");
	sprintf(queries, "INSERT INTO link VALUES('%s', '%s');", dup_ret_stmt, ret_stmt);
	ret_val = sqlite3_exec(handle, queries,0,0,0);
	if(ret_val){
		printf("SQLite does not support inserting more than once.\n");
	}

}

main(){
	system("clear");
	printf("Samantha 0.1.0 (first version, May 6 2015, 00:23)\n");
	printf("A stupid implementation of Artificial Intelligence.\n");
	printf("Running on GNU/linux platform\n\n");
	printf("Samantha is free software; you can redistribute it and/or modify it under the\n");
	printf("terms of the GNU General Public License as published by the Free Software Foundation;\n");
	printf("either version 3 of the License, or (at your option) any later version. Samantha is \n");
	printf("distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even\n");
	printf("the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n");
	printf("\nSee the GNU General Public License for more details. You should have received a copy\n");
	printf("of the GNU General Public License along with Samantha; if not, write to the \n");
	printf("Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA\n");

	printf("\nType something for it to reply to, type \"bye\" to exit.\n");


	char input[100],output[200], ret_stmt[100], dup_ret_stmt[100];
	int ret_val;
	char response[5];

	char str[10];
	int no_of_words = 1;
	FILE *fp, *fp1, *fp3, *fp4;
	int i = 0, j = 0, k = 0;

	int a = 0; int b = 0;

	char queries[100];

	
	while( (strcasecmp(input, "bye") != 0) && (strcasecmp(input, "bye samantha") != 0) ){
		fp = fopen("input.txt", "w");
		printf(">>> ");
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
		ret_val = mapper2(ret_stmt);
		if(!ret_val){
			printf("That query does not have an answer do you want to type an answer?\n");
			printf("=== ");
			scanf(" %s", response);
			if(strcasecmp(response, "yes") == 0){
				sprintf(dup_ret_stmt, "%s", ret_stmt);
				printf("=== ");
				scanf(" %[^\n]s", input);

				fp4 = fopen("input.txt", "w");
				fprintf(fp4, "%s\n", input);
				fclose(fp4);
				system("./test1 <input.txt >output.txt");
				
				fp3 = fopen("output.txt", "r");

				sprintf(ret_stmt," ");
				for(j = 0; fgets(output, 80, fp3)!=NULL; j++){
					sscanf(output, "rowid=%d columnid=%d", &a, &b);
					sprintf(str, "%d %d#", a, b);
					strcat(ret_stmt, str);
				}
				printf("%s\n", ret_stmt);
				fclose(fp3);

				insertingone(dup_ret_stmt, ret_stmt);
			}
		}
	}
}
