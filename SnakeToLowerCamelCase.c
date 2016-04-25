/*
Novjean J Kannathara
Purdue University
novjeanj@gmail.com
*/
/*
Snake case to lower camel case

Snake case = hello_world_how_are_you
Lower camel case = helloWorldHowAreYou

Future:
Improve time complexity because of the two loops
*/

#define _CRT_SECURE_NO_WARNINGS //used for VS2013 and above
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>  //to upper function (capitalization)

int main()
{
	int index, j, len;
	char sentence[50];

	printf("\nEnter the string in snake case: ");
	scanf("%s", sentence);

	printf("\nThe sentence before processing is : \n");
	puts(sentence);

	len = strlen(sentence);

	for (index = 0; index < len; index++)
	{
		if (sentence[index] == '_')
		{
			j = index;
			while(sentence[j]!='\0')
			{
				sentence[j] = sentence[j + 1];
				j++;
			}
			sentence[j] = '\0';
			sentence[index] = toupper(sentence[index]);
		}
	}

	printf("\nThe sentence is : \n");
	puts(sentence);
	
	_getch();
	return 0;
}
