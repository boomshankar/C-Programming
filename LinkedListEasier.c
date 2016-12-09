#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}Node;

Node* root = NULL;

void insert(int data){								//inserting at the end
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	if(root == NULL){
		newNode->link = NULL;
		root=newNode;
	}
	else{
		Node* temp = root;
		while(temp->link != NULL){
			temp = temp->link;
		}
		temp->link = newNode;
		newNode->link = NULL;
	}
}

int isEmpty(){
	return root==NULL;
}

void display(){
	Node* temp = root;
	
	if(isEmpty()){
		printf("\nEmpty Linked List.");
		return;
	}
	
	do{
		printf("%d ", temp->data);
		temp = temp->link;
	}while(temp->link != NULL);
	printf("%d ", temp->data);				//to display the last element
}

void delete(int data){
	Node* temp = root;
	Node* previous;
	if(isEmpty()){
		printf("Empty linked list!");
		return;
	}
	else{
		while(temp->link!=NULL){
			if(temp->data == data){
				previous->link = temp->link;
			}
			previous = temp;
			temp = temp->link;
		}
		if(temp->data == data){							//jus for the last element
				previous->link = temp->link;
			}
	}
}


int main(){
	
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	
	display();
	
	delete(40);
	
	display();
	
	return 0;
}
