#include<stdio.h>
#include<conio.h>

typedef struct node
{
	int data;
	struct node* link;
}Node;

Node* head = NULL;

Node* _getnode()
{
	return((Node*)malloc(sizeof(Node*)));
}

void Insert(Node **head)
{
	Node *s = head;
	int check = 1;
	while (check == 1)
	{
		printf("\nEnter the number: ");
		scanf("%d", &s->data);
		printf("Insert more numbers: 1 for yes: ");
		scanf("%d", &check);
		if (check != 1)
		{
			s->link = NULL;
			return;
		}
		else
		{
			s->link = _getnode();
			s = s->link;
		}
	}
	s = head;
}

void Print( Node *p)
{
	if (p == NULL)
		return;
	printf("%d ", p->data);
	Print(p->link);

}

void ReversePrint(Node *p)
{
	if (p == NULL)
		return;
	ReversePrint(p->link);
	printf("%d ", p->data);
}


int main()
{
	Node *s = _getnode();
	s->link = NULL;
	head = s;

	Insert(head);
	printf("\nLinked list is: ");
	Print(head);

	printf("\nLinked list in reverse is : ");
	ReversePrint(head);

	_getch();
	return 0;
}
