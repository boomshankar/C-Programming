/*
Novjean J Kannathara
Purdue University
novjeanj@gmail.com
*/
/*
Display matrix in a spiral manner
*/
#define _CRT_SECURE_NO_WARNINGS  //Use this for VS2013 and higher
#include<stdio.h>
#include<conio.h>
#define SIZE 3

void displayArray(int A[3][3], int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("\t%d", A[i][j]);
		}
		printf("\n");
	}	
}

void printSpiral(int A[3][3], int m, int n)
{
	int R = m-1;  //right
	int B = n-1;  //bottom
	int L = 0;    //left
	int T = 0;    //top
	int dir = 0;  //direction counter
	int i = 0;    //loop variable

	while (T <= B && L <= R)
	{
		if (dir == 0)
		{
			for (i = L; i <= R;i++)
				printf("%d ", A[T][i]);
			T++;
			dir = 1;
		}
		else if (dir == 1)
		{
			for (i = T; i <= B; i++)
				printf("%d ", A[i][R]);
			R--;
			dir = 2;
		}
		else if (dir == 2)
		{
			for (i = R; i >= L; i--)
				printf("%d ", A[B][i]);
			B--;
			dir = 3;
		}
		else if (dir == 3)
		{
			for (i = B; i >= T; i--)
				printf("%d ", A[i][L]);
			L++;
			dir = 0;
		}
	}
}


int main()
{
	int A[SIZE][SIZE];
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("\t[%d][%d] = ",i, j);
			scanf("%d", &A[i][j]);
		}
	}

	displayArray(A, i, j);

	printSpiral(A, i, j);

	_getch();
	return 0;
}
