#include <stdio.h>

int array[] = {4,25,31,7,6,9,21,33,44,45,30};
int n = 11;
int i;

void display() 
{
   	for(i = 0; i < n; i++) 
	{
		printf("%d, ",array[i]);
   	}
	
   	printf("\n");
}

void swap(int x, int y) 
{
	int temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

int partition(int left, int right, int pivot) {
   	int leftPointer = left - 1;
   	int rightPointer = right;

   	while(true) 
   	{
    	while(array[++leftPointer] < pivot) 
		{
    	}
		
     	while(array[--rightPointer] > pivot && rightPointer > 0) 
		{
    	}

      	if(leftPointer >= rightPointer) 
		{
			break;
      	} 
		else 
		{
         	printf("item swapped :%d <-> %d\n", array[leftPointer], array[rightPointer]);
         	swap(leftPointer, rightPointer);
      	}
   	}
	
   	printf("Pivot swap :%d <-> %d\n", array[leftPointer],array[right]);
   	swap(leftPointer, right);
   	printf("Array: "); 
   
   	display();
   
   	return leftPointer;
}

void quickSort(int left, int right) 
{
   	if(right - left <= 0) 
	{
    	return;   
   	} 
	else 
	{
    	int pivot = array[right];
    	int partitionPoint = partition(left, right, pivot);
    	quickSort(left, partitionPoint-1);
    	quickSort(partitionPoint+1, right);
   	}        
}

int main() 
{
   	display();
   	quickSort(0, n-1);
}
