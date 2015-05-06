#include<stdio.h>
#include<sqlite3.h>
#include<ctype.h>
#include<string.h>
#include"headers/split.h"
#include"headers/sort.h"
void update(char queries[100], char s2[], i){
	if(i == 0)
	sprintf(queries, "select rowid from words where adjective='%s'", s2);
	if(i == 1)
	sprintf(queries, "select rowid from words where adverb='%s'", s2);
	if(i == 2)
	sprintf(queries, "select rowid from words where conjunction='%s'", s2);
	if(i == 3)
	sprintf(queries, "select rowid from words where determiner='%s'", s2);
	if(i == 4)
	sprintf(queries, "select rowid from words where nouns='%s'", s2);
	if(i == 5)
	sprintf(queries, "select rowid from words where prefix='%s'", s2);
	if(i == 6)
	sprintf(queries, "select rowid from words where preposition='%s'", s2);
	if(i == 7)
	sprintf(queries, "select rowid from words where pronoun='%s'", s2);
	if(i == 8)
	sprintf(queries, "select rowid from words where suffix='%s'", s2);
	if(i == 9)
	sprintf(queries, "select rowid from words where verb='%s'", s2);
	if(i == 10)
	sprintf(queries, "select rowid from words where punctuation='%s'", s2);
	if(i == 11)
	sprintf(queries, "select rowid from words where intergection='%s'", s2);
	if(i == 12)
	sprintf(queries, "select rowid from words where unknown='%s'", s2);	
}

main(){
	int ret_val1, ret_val;

	char queries[100];
	sqlite3_stmt *stmt;
	sqlite3 *handle;

	int no_of_words = 1;

	char s1[20], **s2;
	int i = 0;
	int j = 0;
	ret_val = sqlite3_open("listofwords.sqlite3", &handle);

	if(ret_val){
		printf("failed\n");
	}

	scanf("%[^\n]s", s1);
	for(i = 0; i<strlen(s1); i++){
		if(s1[i] == ' '){
			no_of_words += 1;
		}
	}

	s2 = split(s1);


	for(i = 0,j = 0; i<no_of_words*13; i++){
		j = i/13;

		ret_val = sqlite3_prepare_v2(handle, queries,  -1, &stmt, 0);
		if(ret_val){
			update(queries, s2[j], i%13);
			continue;
			// printf("selecting failed\n");
		}
		ret_val = sqlite3_step(stmt);

		if(ret_val == SQLITE_ROW){
			const char *val = (const char*)sqlite3_column_text(stmt, 0);
			printf("%s = %s\n",sqlite3_column_name(stmt, 0), val);
		}
	}
	sqlite3_close(handle);
}