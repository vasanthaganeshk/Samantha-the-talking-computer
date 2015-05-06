#include<stdio.h>
#include<sqlite3.h>
#include<ctype.h>
#include<string.h>
#include"headers/split.h"
#include"headers/sort.h"
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

	for(i = 0; i<no_of_words; i++){
		sprintf(queries, "select rowid from words where nouns='%s'", s2[i]);

		ret_val = sqlite3_prepare_v2(handle, queries,  -1, &stmt, 0);
		if(ret_val){
			printf("selecting failed\n");
		}
		ret_val = sqlite3_step(stmt);

		if(ret_val == SQLITE_ROW){
			const char *val = (const char*)sqlite3_column_text(stmt, 0);
			printf("%s = %s\n",sqlite3_column_name(stmt, 0), val);
		}
	}
	sqlite3_close(handle);
}