/*
Novjean J Kannathara
Purdue University
novjeanj@gmail.com
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define SIZE 10

int numbers[SIZE];

void swap(int i, int j)
{
	int temp;
	temp = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = temp;
}

int partition(int start, int end)
{
	int pivot = numbers[end];
	int pIndex = start;
	int i;

	for (i = start; i < end; i++)
	{
		if (numbers[i] <= pivot)
		{
			swap(i, pIndex);
			pIndex++;
		}
	}
	swap(pIndex, end);
	return pIndex;



	return pIndex;
}

void quicksort(int start, int end)
{
	int pIndex = 0;

	if (start <= end)
	{
		pIndex = partition(start, end);
		quicksort(start, pIndex - 1);
		quicksort(pIndex + 1, end);
		pIndex++;
	}
	else
		return;
}

void displayArray(int count)
{
	int index;
	printf("\nThe array is: \n");
	for (index = 0; index < count; index++)
	{
		printf("%d ", numbers[index]);
	}
}

int binarySearch(int low, int high, int num, bool SearchFirst)
{
	int result=-1;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if (num == numbers[mid])
		{
			if (SearchFirst)
			{
				result = mid;
				high = mid - 1; //lower indices where number is present
			}
			else
			{
				result = mid;
				low = mid + 1; //higher indices where number is present
			}
			
			//return mid;  return to determine whether the numbers exists
		}
		else if (num < numbers[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return result;
}

int main()
{
	int index = 0, count = 0;
	int start, end;
	int num;

	while (index<SIZE)
	{
		printf("\nEnter the numbers into the array, use -1 to stop: ");
		scanf("%d", &numbers[index]);
		if (numbers[index] == -1)
			break;
		index++;
		count++;
	}
	displayArray(count);

	start = 0;
	end = count - 1;
	quicksort(start, end);

	displayArray(count);

	printf("\nEnter the number to be searched: ");
	scanf("%d", &num);
	
	int firstIndex = binarySearch(start, end, num, true);

	if (firstIndex == -1)
	{
		
		printf("\nThe count of %d = %d", num, 0);
	}
	else
	{

		int lastIndex = binarySearch(start, end, num, false);
		printf("\nThe count of %d = %d", num, (lastIndex-firstIndex+1));
	}

	_getch();
	return 0;
}
