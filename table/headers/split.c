#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define and &&
#define or ||

char **split(char sentence[]){
	int no_of_words = 1;
	char *temp, **c;
	int i = 0, j = 0, k = 0;

	for(i = 0; i<strlen(sentence); i++){
		if(sentence[i] == ' '){
			no_of_words += 1;
		}
	}
	c = malloc( no_of_words*sizeof( char* ));

	for ( i = 0; i < no_of_words; i++ )
	{	
		temp = malloc(50);
		k = 0;
		while(sentence[j] != ' ' and sentence[j] != '\0')
		{	
			temp[k] = sentence[j];
			k++;
			j++;
		}
		j++;
		temp[k] = '\0';
	  	c[i] = malloc( strlen(temp) );
	  	sprintf(c[i], "%s", temp);
	  	free(temp);
	}

	return c;

}
