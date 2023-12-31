#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int a[100];
int n;

void print_array(int arr[], int m) 
{
    int i;
	
	for (i = 0; i < m; i++)
	{
		printf("%d  ", arr[i]);
	}
    printf("\n");
}

void bubble_sort(int arr1[], int k)
{
	int j, m, aux;
	
	m = k - 1;
	
	while (m > 0)
	{
		for (j = 0; j < m; j++)
		{
			if (arr1[j] > arr1[j+1])
			{
				aux = arr1[j+1];
				arr1[j+1] = arr1[j];
				arr1[j] = aux;
			}
		}
		m--;
	}
}

void selection_sort(int arr2[], int v)
{
	int i, j, f, auxil, pos_min;
	
	f = v - 1;
	
	for (i = 0; i < f; i++)
	{
		pos_min = i;
		
		for (j = i + 1; j < v; j++)
		{
			if (arr2[j] < arr2[pos_min])
			{
				pos_min = j;
			}
		}
		
		if (pos_min != i)
		{
			auxil = arr2[i];
			arr2[i] = arr2[pos_min];
			arr2[pos_min] = auxil;
		}
	}
}

void insertion_sort(int arr3[], int w)
{
	int i, j, key;
	
	for (i = 1; i < w; i++)
	{
		key = arr3[i];
		j = i - 1;
		
		while (j >= 0 && arr3[j] > key)
		{
			arr3[j + 1] = arr3[j];
			j = j - 1;
		}		
		arr3[j + 1] = key;
	}
}

void swap(int *x, int *y)
{
	int temp = *x; 
	*x = *y;
	*y = temp; 
}

int partition(int arr4[], int low, int high)
{
	int pivot_value, pivot_index, i, j;
	
	pivot_index = low + (rand() % (high - low));
	
	if (pivot_index != high)
	{
		swap(&arr4[pivot_index], &arr4[high]);
	}
	
	pivot_value = arr4[high];
	i = low;
	
	for (j = low; j < high; j++)
	{
		if (arr4[j] <= pivot_value)
		{
			swap(&arr4[i], &arr4[j]);
			i++;
		}
	}
	
	swap(&arr4[i], &arr4[high]);
	
	return i;
}

void quick_sort_recursion(int arr4[], int low, int high)
{
	int pivot_index;
	
	if (low < high)
	{
		pivot_index = partition(arr4, low, high);
		quick_sort_recursion(arr4, low, pivot_index - 1);
		quick_sort_recursion(arr4, pivot_index + 1, high);
	}
}

void quick_sort(int arr4[], int z)
{
	srand(time(NULL));
	
	quick_sort_recursion(arr4, 0, z - 1);	
}

int main ()
{
	int i;
	
	int BubbleCopy[100];
	int SelectionCopy[100];
	int InsertionCopy[100];
	int QuickCopy[100];
	
	clock_t start_time, end_time;
    double execution_time;
    double elapsed_time;
	
	printf("Introduce the number of elements n = ");
	scanf("%d", &n);
	
	printf("Give %d values for the array:\n", n);
	
	for (i=0; i<n; i++)
	{
		printf("a%d = ", i+1);
		scanf("%d", &a[i]);
	}
	printf("\n");
	
	printf("The unsorted array: \n");
	print_array(a, n);
	printf("\n");
	
	memcpy(BubbleCopy, a, n*sizeof(int));
	start_time = clock();
    bubble_sort(BubbleCopy, n);	
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("The BubbleSort-ed array: \n");
	printf("Time taken to execute bubblesort: %f seconds\n", elapsed_time);
	print_array(BubbleCopy, n);
    printf("\n\n");
	
	
	memcpy(SelectionCopy, a, n*sizeof(int));
	start_time = clock();
	selection_sort(SelectionCopy, n);
	end_time = clock();
	elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("The SelectionSort-ed array: \n");
	printf("Execution time of SelectionSort: %f seconds\n", elapsed_time);
    print_array(SelectionCopy, n);
    printf("\n\n");
	
	memcpy(InsertionCopy, a, n*sizeof(int));
	start_time = clock();
	insertion_sort(InsertionCopy, n);
	end_time = clock();
	elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("The InsertionSort-ed array: \n");
	printf("Execution time of InsertionSort: %f seconds\n", elapsed_time);
	print_array(InsertionCopy, n);
    printf("\n\n");
	
	memcpy(QuickCopy, a, n*sizeof(int));
	start_time = clock();
	quick_sort(QuickCopy, n);
	end_time = clock();
	elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("The QuickSort-ed array: \n");
    printf("Execution time of QuickSort: %f seconds\n", elapsed_time);
    print_array(QuickCopy, n);
    printf("\n\n");		
}
