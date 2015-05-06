#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>
int main(){
	int ret_val;

	int q_cnt = 1000, q_size = 800;

	char **queries = malloc(sizeof(char) * q_cnt * q_size);
	sqlite3_stmt *stmt;
	sqlite3 *handle;

	ret_val = sqlite3_open("linking.sqlite3", &handle);
	char create_table[] = {"CREATE TABLE IF NOT EXISTS link(\
	input TEXT PRIMARY KEY NOT NULL,\
	output TEXT NOT NULL);"};

	sqlite3_exec(handle, create_table, 0, 0, 0);
	
}