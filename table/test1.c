#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"headers/split.h"
#include"headers/mapper.h"

main(){
	int no_of_words = 1;

	char s1[20], **s2, **id_row_column;
	int i = 0;
	int j = 0;

	scanf("%[^\n]s", s1);
	for(i = 0; i<strlen(s1); i++){
		if(s1[i] == ' '){
			no_of_words += 1;
		}
	}

	s2 = split(s1);
	id_row_column = mapper(s2, no_of_words);

	for(i = 0; i<no_of_words; i++){
		printf("%s\n",id_row_column[i] );
	}
}

