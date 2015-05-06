#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>
int main(){
	int ret_val;

	sqlite3 *handle;

	ret_val = sqlite3_open("listofwords.sqlite3", &handle);
	char create_table[] = {"CREATE TABLE IF NOT EXISTS words(\
	rowid INTEGER PRIMARY KEY NOT NULL,\
	adjective TEXT,\
	adverb TEXT,\
	conjunction TEXT,\
	determiner TEXT,\
	nouns TEXT,\
	prefix TEXT,\
	preposition TEXT,\
	pronoun TEXT,\
	suffix TEXT,\
	verb TEXT,\
	punctuation TEXT,\
	intergection TEXT,\
	unknown TEXT);"};

	sqlite3_exec(handle, create_table, 0, 0, 0);
	sqlite3_close(handle);

}