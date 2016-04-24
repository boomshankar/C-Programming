/*Name: Novjean J Kannathara
Date: 1/19/2015
Program: Tic-Tac-Toe Game
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

void display(int a[], int count);
int check(int a[]);

int main()
{
	int a[9];													//1D array to store the values
	int count=0;
	int i , position;
	int player = 0;
	int winner = -1;

	printf("\nTic-Tac-Toe position Layout.\n\n");				//Displaying the layout for user to understand
	for (i = 0; i < 9; i++)
		a[i] = i+1;
	display(a, i);

	for (i = 0; i < 9; i++)										//Initializing the array with all values set to -9
		a[i] = -9;

	for (i = 0; i < 9; i++)
	{
		
		printf("\nPlayer %d,Your Move.\nWhich position do you want to play at: ",player);
		scanf("%d", &position);
		while (position <= 0 || position >= 10 || a[position-1] !=-9)						//Validating the position entered
		{
			printf("\nIncorrect position, please enter again: ");
			scanf("%d", &position);
		} 
		position = position - 1;
		if (player == 0)										//Entering value into the array based on which player played
			a[position] = 0;
		else
		a[position] = 1;
		display(a, i);

		if (player==0)											//Switching players for next loop
			player = 1;
		else
			player = 0;
		winner = check_winner(a);								//Invoke check_winner to determine if there is a winner
		if (winner ==0 ||winner==1)
		{
			printf("\n\nWinner is player %d. Congratulations!!!", winner);
			break;
		}
	}
	if (i==9)
		printf("\nThe game is a draw. Well Played.");
	_getch();
	return 0;
}

void display(int a[], int count)
{
	int i,temp;
	for (i = 0; i < 9; i++)
	{		
		if (i % 3 == 0 && i!=0)									//Drawing the horizontal lines 
		{
			printf("\n");
			printf("-----------");
			printf("\n");			
		}
		if (a[i] == -9)											//Displaying blank spaces in the box instead of -9
			printf("  | ");
		else
		printf("%d | ", a[i]);
	}
	printf("\n\n");
}

int check_winner(int a[])
{
	int i;
	int sum = -1;
	int win = -1;
	for (i = 0; i < 9; i = i + 3)												//loop for checking each row
	{
		sum = a[i] + a[i + 1] + a[i + 2];
		if (sum == 3 || sum == 0)		
			win = sum / 3;
	}
	for (i = 0; i < 3; i++)														//loop for checking each column
	{
		sum = a[i] + a[i + 3] + a[i + 6];
		if (sum == 3 || sum == 0)
			win = sum / 3;
	}

	sum = a[2] + a[4] + a[6];													//checking the diagonal
	if (sum == 3 || sum == 0)
		win = sum / 3;

	sum = a[0] + a[4] + a[8];													//checking the diagonal
	if (sum == 3 || sum == 0)
		win = sum / 3;
	
	return win;
}
