/*
Novjean J Kannathara
novjeanj@gmail.com
Purdue University
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>


#define SIZE 10
int numbers[SIZE];


void display(int numbers[], int count)
{
	int index;

	printf("\nThe array is: ");
	for (index = 0; index<count; index++)
	{
		printf("\n[%d] = [%d]", index, numbers[index]);
	}
}

void swap(int i, int j)
{
	int temp;
	temp = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = temp;
}

void bubblesort(int numbers[], int count)
{
	int index, i, j, num;
	int swapped = 0;

	for (i = 0; i<count - 1; i++)
	{
		swapped = 0;
		for (j = 0; j<count - 1 - i; j++)
		{
			printf("\nItems compared: [%d, %d]", numbers[j], numbers[j + 1]);
			if (numbers[j]>numbers[j + 1])
			{
				printf("\nItems swapped: [%d, %d]", numbers[j], numbers[j + 1]);
				swap(j, j + 1);
				swapped = 1;
			}
			else
			{
				printf("\nNot swapped");
			}
		}
		if (swapped == 0)
			break;
	}


}

void insertionSort(int count)
{
	int i;
	int value, hole;

	for (i = 1; i<count; i++)
	{
		value = numbers[i];
		hole = i;
		printf("\nItems compared: [%d, %d]", numbers[hole - 1], numbers[i]);
		while (hole>0 && numbers[hole - 1]>value)
		{
			numbers[hole] = numbers[hole - 1];
			hole--;
			printf("\nItems swapped: [%d, %d]", numbers[hole], numbers[hole - 1]);
		}
		numbers[hole] = value;
	}

}

int Partition(int start, int end)
{
	int pivot = numbers[end];
	int i;
	int pIndex = start;
	printf("\n---------------------------------------");
	printf("\nPivot = %d", pivot);
	printf("\npIndex = %d", pIndex);


	for (i = start; i < end; i++)
	{
		printf("\nItems compared: [%d, %d]", numbers[i], pivot);
		if (numbers[i] <= pivot)
		{
			printf("\nItems swapping: [%d, %d]", numbers[i], numbers[pIndex]);
			swap(i, pIndex);
			pIndex = pIndex + 1;
			display(numbers, end + 1);
			printf("\npIndex = %d", pIndex);
		}
	}
	printf("\nSwapping pivot: [%d, %d]", numbers[i], numbers[pIndex]);
	swap(pIndex, end);
	display(numbers, end + 1);
	return pIndex;

}

void quicksort(int start, int end)
{
	printf("\nstart = %d", start);
	printf("\nend = %d", end);
	if (start<end)
	{
		int pIndex = Partition(start, end);
		quicksort(start, pIndex - 1);
		quicksort(pIndex + 1, end);
		printf("\nDone sorting\n.");
	}
	else
		return;
}

int fillArray()
{
	int index, num, count = 0;

	printf("\nEnter the data into the array, -1 to break: \n");
	for (index = 0; index<SIZE; index++)
	{
		printf("\n[%d] = ", index);
		scanf("%d", &num);
		if (num == -1)
		{
			break;
		}
		numbers[index] = num;
		count++;
	}
}

int main()
{
	int count = 0;
	int start, end, option;

	count = fillArray();
	display(numbers, count);

	printf("\nSelect a Sorting Method: ");
	printf("\n1. Bubble Sort");
	printf("\n2. Inserion Sort");
	printf("\n3. Quick Sort");
	printf("\n4. Exit");
	scanf("%d", &option);

	switch (option)
	{
	case 1:
		bubblesort(numbers, count);
		display(numbers, count);
		break;
	case 2:
		insertionSort(count);
		display(numbers, count);
		break;
	case 3:
		start = 0;
		end = count - 1;
		quicksort(start, end);
		display(numbers, count);
		break;
	default:
		printf("\nInvalid choice.");
		break;
	}

	_getch();
	return 0;
}