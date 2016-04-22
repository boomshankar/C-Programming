#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

#define SIZE 8
int stack[SIZE];
int top = -1;

int isEmpty()
{
	if(top ==-1)
	{
		return 0;
	}
	else 
		return 1;
}

int isFull()
{
	int index = top + 1;
	if(index>=SIZE)
		return 0;
	else
		return 1;
}

void push(int data)
{
	int index = top + 1;
	if(isFull() == 0)
	{
		printf("\nThe stack is full.");
	}
	else
	{
		stack[index] = data;
		++top;
	}
}

void pop()
{
	int data;
	if(isEmpty() == 0)
	{
		printf("\nThe stack is empty. Cannot pop.");
		return;
	}
	else
	{
		data = stack[top];
		top--;
		printf("\n%d has been popped from the stack.", data);
	}
}

void display()
{

	if(isEmpty() == 0)
	{
		printf("\nThe stack is empty");
	}
	else
	{
		int index = top;
		printf("\nThe Stack is : \n");
		for(index = top; index>=0;index--)
		{
			printf("[%d]\n", stack[index]);
		}
	}

}

int peek()
{
	if(isEmpty() == 0)
	{
		printf("\nThe stack is empty");
	}
	else
		return stack[top];
}

int main()
{
	int check = 0;
	int data;

	do
	{
		printf("\nEnter the data to be added to stack: ");
		scanf("%d", &data);
		push(data);
		printf("\nDo you want to add more: 1 for yes, 0 for no: ");
		scanf("%d", &check);
	}while(check == 1);

	display();

	pop();
	display();

	data = peek();
	printf("\nThe peek value is %d: ", data);

	_getch();
	return 0;
}