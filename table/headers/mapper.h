#include<stdio.h>
#include<sqlite3.h>
#include<ctype.h>
#include<string.h>


#define True 1
#define False 0

void update(char queries[100], char s2[],int i){
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
	if(i == -1)
	sprintf(queries, "select rowid from words where unknown='%s'", s2);
}

char **mapper(char **s2, int no_of_words){
	int ret_val1, ret_val;
	int flag = False;

	char queries[100], statement[100], **ret_stmt;
	char ret_stament[200];

	int ret_count = 0;
	sqlite3_stmt *stmt;
	sqlite3 *handle;

	int i = 0;
	int j = 0;


	ret_stmt = (char **)calloc( no_of_words, sizeof( char* ));
	for(i = 0; i<no_of_words; i++){
		ret_stmt[i] = (char *)calloc(100, sizeof(char));
	}

	ret_val = sqlite3_open("listofwords.sqlite3", &handle);

	if(ret_val){
		printf("failed\n");
	}


	for(i = 0,j = 0; i<no_of_words*13; i++){
		j = i/13;
		if(i%13 == 0){
			flag = False;
		}
	
		update(queries, s2[j], i%13);
		ret_val = sqlite3_prepare_v2(handle, queries,  -1, &stmt, 0);
		if(ret_val){
			continue;
			// printf("selecting failed\n");
		}
		ret_val = sqlite3_step(stmt);

		//updation of i can come here to reduce the number of iterations

		if(ret_val == SQLITE_ROW and flag == False){
			flag = True;
			const char *val = (const char*)sqlite3_column_text(stmt, 0);
			// printf("%s = %s, %d\n",sqlite3_column_name(stmt, 0), val, (i%13));
			sprintf(ret_stmt[ret_count], "%s=%s columnid=%d",sqlite3_column_name(stmt, 0), val, (i%13));
			ret_count++;

		}
		else if(flag == False and (i%13) == 12){
			// add the word to unknown
			sprintf(statement, "UPDATE words SET unknown='%s' WHERE unknown IS NULL LIMIT 1;", s2[j]);
			sqlite3_exec(handle,statement,0,0,0);
			update(queries, s2[j], 12);

			ret_val = sqlite3_prepare_v2(handle, queries,  -1, &stmt, 0);
			if(ret_val){
				continue;
				// printf("selecting failed\n");
			}
			ret_val = sqlite3_step(stmt);

			//updation of i can come here to reduce the number of iterations

			if(ret_val == SQLITE_ROW and flag == False){
				flag = True;
				const char *val = (const char*)sqlite3_column_text(stmt, 0);
				// printf("%s = %s, %d\n",sqlite3_column_name(stmt, 0), val, (i%13));
				sprintf(ret_stmt[ret_count], "%s=%s columnid=%d",sqlite3_column_name(stmt, 0), val, (i%13));
				ret_count++;

			}
			// printf("Added new word '%s' to table\n", s2[j]);
		
		}
	}
	sqlite3_close(handle);
	return ret_stmt;
}