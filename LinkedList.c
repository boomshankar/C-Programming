/*Novjean J Kannathara
Purdue University
nkannath@purdue.edu*/

#define _CRT_SECURE_NO_WARNINGS //If using Visual studio 2013 or higher
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}Node;

Node *head = NULL;

Node *_getnode()
{
	return ((Node *)(malloc(sizeof(Node))));
}

void display(Node **head)
{
	Node *s = head;

	//printf("\nhead = [%p]\n", head);

	printf("\nThe linked list is :");
	printf("\n[Addr] = [Data]\n");
	while (s != NULL)
	{
		printf("[%p] -> [%d]\n", s->link, s->data);
		s = s->link;
	}
	//	printf("null");
}

void insertion(Node **head)
{
	int check = 1;
	Node *s = head;
	while (check == 1)
	{
		printf("\nEnter the data: ");
		scanf("%d", &s->data);
		printf("\nDo you want to add more: 1 for yes, 0 for no: ");
		scanf("%d", &check);
		if (check != 1)
		{
			s->link = NULL;  //adding NULL to the last node
			break;
		}
		else
		{
			s->link = _getnode();
			s = s->link;
		}

	}
	s = head;
}

Node* deletion(Node **head) 
{
	int check = 1;
	int deleteValue;
	Node *current = head;
	Node *previous = current;

	printf("\nEnter the index to be deleted: ");
	scanf("%d", &deleteValue);

	//printf("\nhead = [%p]\n", head);
	
	while (current != NULL)
	{
		//printf("\nPrevious: [%p] = %d", previous->link, previous -> data);
		//printf(" Current: [%p] = %d", current->link, current->data);

		if (current->data == deleteValue)
		{
//			printf("\nInside the loop finding the data: \n");
//			printf("\nPrevious: [%p] = %d", previous->link, previous->data);
//			printf(" Current: [%p] = %d", current->link, current->data);

			previous->link = current->link;

//			printf("\nAfter modifying finding the links: \n");
//			printf("\nPrevious: [%p] = %d", previous->link, previous->data);
//			printf(" Current: [%p] = %d", current->link, current->data);

			if (current == head)
			{
				//printf("\nInside the flow if current == head: \n");
				//printf("\nPrevious: [%p] = %d", previous->link, previous->data);
				//printf(" Current: [%p] = %d ", current->link, current->data);
				//printf(" head = [%p]", head);

				head = current->link;

/*				printf("\nAfter modifying the head if current == head: \n");
				printf("\nPrevious: [%p] = %d", previous->link, previous->data);
				printf(" Current: [%p] = %d ", current->link, current->data);
				printf(" head = [%p]", head);*/	
			}		
			free(current);
			break;
		}
		previous = current;
		current = current->link;
	}
//	printf("\nAfter the loop, head = [%p]", head);
	return head;

}

int main()
{
	Node *s = _getnode();
	s->link = NULL;
	head = s;

	insertion(head);
	display(head);

	head = deletion(head);
//	printf("\nAfter deletion, head = [%p]", head);
	display(head);

	_getch();
	return 0;
}
