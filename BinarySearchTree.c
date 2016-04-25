/*
Novjean J Kannathara
Purdue University
novjeanj@gmail.com
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BstNode
{
	int data;
	struct BstNode* left;
	struct BstNode* right;
}BstNode;

BstNode* GetNewNode(int data)
{
	BstNode* newNode = (BstNode*)malloc(sizeof(BstNode));  //Gotto check this
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL)
	{
		root = GetNewNode(data);
	}
	else if(data<=root->data)
	{
		root->left = Insert(root->left, data); 
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;				//return the root because root is local to main

}

bool Search(BstNode* root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (data == root->data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}

}

int main()
{
	int num;

	BstNode* root;  //to store address of root node
	root = NULL; //empty tree
	
	root = Insert(root, 15);  //the root pointer will point to the first node
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	root = Insert(root, 6);

	printf("\nEnter the number to be searched: ");
	scanf("%d", &num);

	if (Search(root,num))
	{
		printf("\nFound.");
	}
	else
	{
		printf("\nNot found.");
	}

	_getch();
	return 0;
}


/*
Notes:
Roots and nodes
links of nodes is children
children are derived from its parents
children of same parent are called sibling
leafs are nodes without parents
parent of parent is called a grandparent
cousins, uncles etc.

Walking in a tree is directional

Tree is called a recursive data sructure
recursive is reducing something in a similar manner

tree with N nodes will have n-1 edges
There will be only one incoming link to any node

hieght of an emptry tree = -1
height of tree with 1 node = 0

when x is any node,
depth of x = length of path from root to x (number of edges from root to path)
height of x = no. of edges in longest path from x to a leaf
height of tree = height of root node

binary tree, any node on the tree cannot have more than two children
one is left_child and other is right_child

complete binary tree:
all levels except the last are completely filled and all nodes are as left as possible
max no of nodes at level i = 2^i
hieght = log2(n)

perfect binary tree:
all nodes except leaves will have exact 2 childrren
max number of nodes = 2^(no_of_levels+1) - 1
if n nodes, then max hieght h = log2(n+1) - 1 //its jus the math

hieght of a tree will be less if the tree is dense
if n nodes,
min height = log2(n) // O(h) = O(log2(n))

In sparse tree:
max height = n-1 // O(h) = O(n)

balanced binary tree:
difference between height of left and right subtree for every node is not more than 1
diff = abs(hleft - hright)


if height is minimized, cost of various operations that depend on height is minimized

implementation methods:
dynamically created nodes (doubly linked lists)
arrays(complete binary trees):
for node at index i;
left_child_index = 2*i+1
right_chile_index = 2*i+2

Binary Search Tree:
binary tree in which for each node, value of all the nodes in left subtree is lesser than the value of all nodes in the right subtree
both left and right subtrees should also be BST
We perform a binary search
time complexity, O(n) = log2(n) //this is pretty small
avoid worst case by keeping the binary tree is balanced

Nodes will be created in heap
dynamic memory allocation
gotto use malloc, realloc, calloc and free


applications of tree:
storing naturally hierarchial data
organize data for quicksearch, insertion, deletion
Trie, used for storing dictionary
network routing algorithms

*/
