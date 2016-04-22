/*
Novjean J Kannathara
novjeanj@gmail.com
Purdue University
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

#define SIZE 8
int queue[SIZE];
int front = 0;
int rear = -1;

int isFull()
{
	if(front>=SIZE)
		return 0;
	else return 1;
}

int isEmpty()
{
	if(rear<0)
		return 0;
	else return 1;
}

void display()
{
	int index;
	if(isEmpty() == 0)
	{
		printf("\nThe queue is empty");
		return;
	}
	else 
	{
		printf("front = %d ", front);

		printf("\nThe queue is: \n");
		for(index = front-1; index>=rear; index--)  //front-1 because it goes one more index that required.
		{
			printf("[%d]\n", queue[index]);
		}
	}
}

void insert(int data)
{
	int index = front;


	if(isFull()==0)
	{
		printf("\nThe queue is full.");
		return;
	}
	else
	{
		queue[index] = data;
		front++;
		rear = 0;
	}
	
}

void pop()
{
	int index;
	if(isEmpty() == 0)
	{
		printf("\nThe queue is empty");
		return;
	}
	else 
	{
		for(index = rear; index<front;index++)
			queue[index] = queue[index+1];
	}
	queue[index]='\0';
	front--;

}

int main()
{
	int check = 0;
	int data;

	do
	{
		printf("\nEnter the data to be added to queue: ");
		scanf("%d", &data);
		insert(data);
		printf("\nDo you want to add more: 1 for yes, 0 for no: ");
		scanf("%d", &check);
	}while(check == 1);

	display();
	pop();
	display();

	_getch();
	return 0;
}