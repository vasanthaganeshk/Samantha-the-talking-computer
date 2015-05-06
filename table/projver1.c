#include"headers/split.h"
#include"headers/mapper.h"
#include<ctype.h>

main(){
	char input[100] = {""};
	char answer[100] = {""};
	int no_of_words = 1;

	char **s2, **id_input, **id_answer;
	int i = 0;
	int j = 0;	

	while( (strcasecmp(input, "bye") != 0) && (strcasecmp(input, "bye samantha") != 0) ){
		printf(">>>");
		scanf(" %[^\n]s", input);

		s2 = split(input);

		for(i = 0; i<strlen(input); i++){
			if(input[i] == ' '){
				no_of_words += 1;
			}
		}

		id_input = mapper(s2, no_of_words);

		for(i = 0; i<no_of_words; i++){
			printf("%s\n",id_input[i] );
		}
		free(id_input);
		// if(strcasecmp(input, ".add_answer") == 0){
		// 	printf("<<<");
		// 	scanf(" %s", answer);
		// 	s2 = split(answer);
		// 	for(i = 0; i<strlen(answer); i++){
		// 		if(answer[i] == ' '){
		// 			no_of_words += 1;
		// 		}
		// 	}

			
		// 	id_answer = mapper(s2, no_of_words);

		// 	for(i = 0; i<no_of_words; i++){
		// 		printf("%s\n",id_answer[i] );
		// 	}
		// 	free(id_answer);

		// }
	}
}
