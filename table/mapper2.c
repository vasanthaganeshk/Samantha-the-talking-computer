#include"headers/execute.h"
#include"headers/stater.h"
#include<sqlite3.h>

#define and &&
#define or ||

int main(){
	sqlite3_stmt *stmt;
	sqlite3 *handle;
	int ret_val;
	char queries[100];
	char input[]={" "};

	char ret_stmt[100];

	ret_val = sqlite3_open("linking.sqlite3", &handle);

	if(ret_val){
		printf("failed\n");
	}


	while(1){
		sprintf(input, "%s",exeq());
		sprintf(queries, "select output from link where input='%s'", input);

		ret_val = sqlite3_prepare_v2(handle, queries,  -1, &stmt, 0);
		if(ret_val){
			printf("selecting failed\n");
		}
		ret_val = sqlite3_step(stmt);

		if(ret_val == SQLITE_ROW){
			const char *val = (const char*)sqlite3_column_text(stmt, 0);
			sprintf(ret_stmt, "%s", val);
			mapper_linked(ret_stmt);
		}
		sqlite3_close(handle);
	}
}
	