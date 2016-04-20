#include<stdio.h>
#include<conio.h>

int insertion(int arr[], int count)
{
	int tempCount = count;
	int value, addIndex;

	printf("The value to be entered: ");
	scanf("%d", &value);
	printf("The index the value to be entered at: ");
	scanf("%d", &addIndex);
	count++;

	while(tempCount>=addIndex)
	{
		arr[tempCount+1] = arr[tempCount];
		tempCount--;
	}

	arr[addIndex] = value;
	return count;
}

int deletion(int arr[], int count)
{
	int tempCount = count;
	int deleteIndex;

	printf("\nEnter the index to be deleted: ");
	scanf("%d", &deleteIndex);

	while(deleteIndex<count)
	{
		arr[deleteIndex] = arr[deleteIndex +1];
		deleteIndex++;
	}
	count--;
	return count;

}

void searching(int arr[], int count)
{
	int value, index, searchIndex;

	printf("\nEnter the value to be searched: ");
	scanf("%d", &value);

	for(index = 0; index<count;index++)
	{
		if(arr[index] == value)
		{	
			searchIndex = index;
			break;
		}
	}
	printf("\nThe value %d is at index %d\n", value, searchIndex);
}

void updating(int arr[], int count)
{
	int updateIndex, value;

	printf("\nEnter the updated value: ");
	scanf("%d", &value);
	printf("\nEnter the index to which the value is to be added to: ");
	scanf("%d", &updateIndex);

	arr[updateIndex] = value;
	printf("\nValue Updated\n");
}
void display(int arr[], int count)
{
	int index;

	for(index = 0; index<count;index++)
	{
		printf("array[%d] = %d\n",index, arr[index]);
	}
}

int main()
{
	int arr[] = {1,2,3,4,5};
	int count  = 5;

//	count = insertion(arr,count);
//	count = deletion(arr,count);
//	searching(arr,count);
	updating(arr,count);
	display(arr,count);

	getch();
	return 0;
}