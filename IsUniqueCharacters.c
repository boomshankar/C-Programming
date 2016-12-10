#include<stdio.h>
#include<conio.h>
#include<string.h>

int isUniueChars(char sentence[]){
	int char_val[256];
	
	for(int i=0; i < strlen(sentence); i++){
		int val = sentence[i];
		//printf("\n Char val wit %d", char_val[val]);
		if(char_val[val] == 1){
			//printf("\n Conflict wit %c", sentence[i]);
			return 0;
		}
			
		char_val[val] = 1;
		
	}
	return 1;
	
}

int main(){
	
	char sentence[50];
	
	printf("\nEnter the sentence: ");
	//scanf("%s", sentence);
	gets(sentence);
	//printf("\nThe sentence is: %s", sentence);
	
	int result = isUniueChars(sentence);
	if(result)
		printf("\n%s has all unique characters.", sentence);
	else printf("\n%s does not have all unique characters.", sentence);
	
	getch();
	return 0;
}
