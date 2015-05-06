#include"headers/split.h"
main(){
	char s1[20], **s2;
	int i = 0;
	int j = 0;
	int no_of_words = 1;

	scanf("%[^\n]s", s1);
	for(i = 0; i<strlen(s1); i++){
		if(s1[i] == ' '){
			no_of_words += 1;
		}
	}

	s2 = split(s1);

	for(i = 0; i<no_of_words; i++){
		printf("%s\n", s2[i]);
	}
}