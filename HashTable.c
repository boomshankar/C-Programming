#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 30

struct DataItem{
	int data ;
	int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key){
	return key % SIZE;
}

void insert(int key, int data){
	struct DataItem* item = (struct DataItem*) malloc (sizeof(struct DataItem));
	item->data = data;
	item->key = key;
	
	int hashIndex = hashCode(key);
	
	while(hashArray[hashIndex]!=NULL && hashArray[hashIndex]->key!=-1){
		hashIndex++;
		hashIndex %= SIZE;
	}
	hashArray[hashIndex] = item;
	
}

struct DataItem* search (int key){
	
	int hashIndex = hashCode(key);
	
	while(hashArray[hashIndex] != NULL){
		if(hashArray[hashIndex]->key == key)
			return hashArray[hashIndex];		
		hashIndex++;
		hashIndex%=SIZE;
	}
	return NULL;
}

int delete(int key){
	int hashIndex = hashCode(key);
	int num;
	
	while(hashArray[hashIndex]!=NULL){
		if(hashArray[hashIndex]->key == key){
			num = hashArray[hashIndex]->data;
			hashArray[hashIndex] = dummyItem;
			return num;
		}
			hashIndex++;
			hashIndex%=SIZE;
	}
	return -1;
}

int main()
{
	dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
	dummyItem->data = -1;
	dummyItem->key = -1;
	
	insert(1,20);
	insert(2, 70);
	insert(42, 80);
	insert(4, 25);
	insert(12, 44);
	insert(14, 32);
	insert(17, 11);
	insert(13, 78);
	insert(37, 97);
	
	item = search(37);
	
	if(item != NULL)
		printf("\nItem was found, %d", item->data);
	else printf("\nItem was not found.");
	
	int num = delete(13);
	if(num != -1)
		printf("\nNumber was found, %d", num);
	else printf("\nNumber was not found.");
	
	getch();
	return 0;
}
