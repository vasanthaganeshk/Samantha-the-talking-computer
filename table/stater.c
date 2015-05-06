#include<stdio.h>
#include<sqlite3.h>
#include<ctype.h>
#include<string.h>

#define True 1
#define False 0

void update(char queries[100], int r_id,int c_id){
	if(c_id == 0)
	sprintf(queries, "select adjective from words where rowid='%s'", r_id);
	if(c_id == 1)
	sprintf(queries, "select adverb from words where rowid='%s'", r_id);
	if(c_id == 2)
	sprintf(queries, "select conjunction from words where rowid='%s'", r_id);
	if(c_id == 3)
	sprintf(queries, "select determiner from words where rowid='%s'", r_id);
	if(c_id == 4)
	sprintf(queries, "select nouns from words where rowid='%s'", r_id);
	if(c_id == 5)
	sprintf(queries, "select prefix from words where rowid='%s'", r_id);
	if(c_id == 6)
	sprintf(queries, "select preposition from words where rowid='%s'", r_id);
	if(c_id == 7)
	sprintf(queries, "select pronoun from words where rowid='%s'", r_id);
	if(c_id == 8)
	sprintf(queries, "select suffix from words where rowid='%s'", r_id);
	if(c_id == 9)
	sprintf(queries, "select verb from words where rowid='%s'", r_id);
	if(c_id == 10)
	sprintf(queries, "select punctuation from words where rowid='%s'", r_id);
	if(c_id == 11)
	sprintf(queries, "select intergection from words where rowid='%s'", r_id);
	if(c_id == 12)
	sprintf(queries, "select unknown from words where rowid='%s'", r_id);
}


void mapper_linked(char *input){
	k = 0;
	int r_id = 0;
	int c_id = 0;

	int ret_val;

	char queries[100], statement[100], **ret_stmt;
	char ret_stament[200];

	int ret_count = 0;
	sqlite3_stmt *stmt;
	sqlite3 *handle;

	int i = 0;
	int j = 0;


	ret_stmt = (char *)calloc( no_of_words, sizeof(char) );

	ret_val = sqlite3_open("listofwords.sqlite3", &handle);
	if(ret_val){
		printf("failed\n");
	}


	for(i = 1; i<strlen(input); i++){
		if(input[i] != '#'){
			temp[k] = input[i] ;
			k++;
		}
		else{
			k = 0;
			sscanf(temp, "%d %d", &r_id, &c_id);
			update(queries, r_id, c_id);

			ret_val = sqlite3_prepare_v2(handle, queries,  -1, &stmt, 0);
			if(ret_val){
				continue;
				// printf("selecting failed\n");
			}
			ret_val = sqlite3_step(stmt);

			if(ret_val == SQLITE_ROW and flag == False){
				const char *val = (const char*)sqlite3_column_text(stmt, 0);
				// printf("%s = %s, %d\n",sqlite3_column_name(stmt, 0), val, (i%13));
				sprintf(ret_stmt, "espeak '%s'",val);
				printf("%s\n", ret_stmt);
				system(ret_stmt);
			}
			sprintf(temp, " ");
		}
	}
}