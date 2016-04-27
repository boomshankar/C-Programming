/*
Novjean J Kannathara
Purdue University
novjeanj@gmail.com
*/
/*
Sorted Array
The array is cyclic and rotated
Determine the number of rotations
*/

#define _CRT_SECURE_NO_WARNINGS  //Used for visual studio 2013 and higher
#include<conio.h>
#include<stdio.h>

int binarySearch(int A[], int low, int high)
{
	int mid, prev, next;
	int count = sizeof(A) / sizeof(A[0]);
	while (low <= high)
	{
		mid = (low + high) / 2;
		next = (mid + 1) % count;           //the modulus function returns remainder and it provides the index next and previous to the mid
		prev = (mid + count- 1) % count;
	
		if(A[low] <= A[high]) //condition where the array/subarray is sorted
		{
			return low; 
		}
		else if (prev>A[mid] && A[mid]<next)  //pivot condition where previous is lesser and next is higher, return mid
		{
			return mid;
		}
		else if(A[mid]<=A[high])  //condiiton where mid value is lesser than high value at index, change the high to mid-1
		{
			high = mid - 1;
		}
		else  //condition where the mid value is greater than high value in index, change the low value to mid+1
		{
			low = mid + 1;
		}
	}
	return -1;  //return if the rotation is incorrect
}

int main()
{
	int A[] = { 11,12,15,18,2,5,6,8 };
	int count = sizeof(A) / sizeof(A[0]);  // to determine the number of elements in the array
	int low = 0;
	int high = count-1; //reduce the count by 1 so as to point to the last element

	int rotationCount = binarySearch(A, low, high);

	printf("\nThe sorted array is rotated %d times.", rotationCount);

	_getch();
	return 0;
}
