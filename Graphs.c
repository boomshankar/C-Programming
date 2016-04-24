/*
Novjean J Kannathara
Purdue University
novjeanj@gmail.com
*/

/*
G = (V,E) // V vertices , E edges
N number of vertices
then max number of directed edges = n(n-1)
then max number of undirected edges = n(n-1)/2 assuming no self-loop or multi-edge

dense = too many edges (adjaceney matrix)
sparse = too few edges (adjacency list)

simple path = no vertices are repeated
trail = a path in which no edges are repeated
closed walk = starts and ends at same vertex
DAG = directed acyclic graph

connected = path from any vertex to any other vertex
strongly connected = directed graph with path from any vertex to other vertex

space = O(|V|+|E|)

Always run comparing number of vertices |V| O(n), rather than E as the number of E can be very high O(n^2)

time to find all nodes to an adjacent node, we would perform a linear search

if
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

//typedef struct Edge
//{
//	int startVertex;  //this points to the index of the vertex list, to save memory
//	int endVertex;
////	int weight;
//};

#define SIZE 10

int main()
{
	int number_of_vertices,i,j, weight;	
	char V[SIZE] = { 'A','B','C','D','E','F','G','H','I','J' };
	int E[SIZE][SIZE];

	printf("\nEnter number of vertices in the graph: ");
	scanf("%d", &number_of_vertices);

	printf("\nEnter the weight if the vertices have edges, enter 0 for no egde: \n");
	for (i = 0; i < number_of_vertices; i++)
	{
		for (j = i; j < number_of_vertices; j++)
		{
			printf("[%c] -> [%c]: ", V[i],V[j]);
			scanf("%d", &weight);
			E[i][j] = weight;
			E[j][i] = weight;
		}
	}

	printf("\nThe adjacency matrix is: \n");
	for (i = 0; i < number_of_vertices; i++)
	{
		for (j = 0; j < number_of_vertices; j++)
		{
			printf("%d\t", E[i][j]);
		}
		printf("\n");
	}




	_getch();
	return 0;
}