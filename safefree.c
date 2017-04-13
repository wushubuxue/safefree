#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void saferfree(void **p)
{
	if(p != NULL && *p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}


int* allocatearray(int *arr, int size, int value)
{
	if(arr != NULL)
	{
		for(int i=0; i<size; i++)
		{
			arr[i] = value;
		}
	}
	return arr;
}

int main()
{
	int* vector = (int*)malloc(5 * sizeof(int));
	allocatearray(vector,5,45);
	for(int i=0; i<5; i++)
	{
		printf("%d\n",vector[i]);	
	} 
	saferfree((void**)&vector);       // 释放内存后程序不会终止 
	return 0;	
}
