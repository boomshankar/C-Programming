#include<stdio.h>

typedef struct node
{
	int data;
	struct node* link;
}Node;

Node* head = NULL;
int count = 0;

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

int Count(Node *p)
{
	if (p == NULL)
		return count;
	count++;
	Count(p->link);

}

void printMiddle(Node *p, int count)
{
	int middle = (count / 2)+1;
	int index = 1;
	if (p == NULL)
	{
		printf("Empty Linked list!!!");
		return;
	}
	while(index<=middle)
	{
		if (index == middle)
		{
			printf("Middle = %d", p->data);
			return;
		}
		p=p->link;
		index++;
	}
}


int main()
{
	Node *s = _getnode();
	s->link = NULL;
	head = s;

	Insert(head);
	count = Count(head);
	printf("\nThe count is %d", count);
	printMiddle(head, count);

	return 0;
}
