#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int start, int mid, int end)
{
	int total = end - start + 1;
	int *array = (int *)malloc(sizeof(int)*total);

	for(int i = 0; i< total;i++)
		array[i] = arr[i+start];

	int left_c = 0;
	int right_c = mid-start+1;
	int l_max = mid-start;
	int r_max = end-start;
	int output_c = start;

	while(left_c <= l_max && right_c <= r_max)
	{
		if(array[left_c] <= array[right_c])
		{
			arr[output_c] = array[left_c];
			output_c++;
			left_c++;
		}
		else
		{
			arr[output_c] = array[right_c];
			output_c++;
			right_c++;
		}
	}
	if(left_c <= l_max)
	{
		while(left_c <= l_max)
		{
			arr[output_c] = array[left_c];
			output_c++;
			left_c++;
		}
	}
	else
	{
		while(right_c <= r_max)
		{
			arr[output_c] = array[right_c];
			output_c++;
			right_c++;
		}
	}


}

void mergesort(int *arr, int start, int end)
{
	if(start<end)
	{
		int mid = (end+start)/2;
		mergesort(arr, start, mid);
		mergesort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main()
{
	int arr[] = {7, -4, 10, -1, 3, 2, -6, 9};
	int size = 8;

	printf("Before Sort : ");
	for(int i = 0;i<8;i++)
		printf("%d , ", arr[i]);
	printf("\n");

	mergesort(arr, 0, size-1);

	for(int i = 0;i<8;i++)
		printf("%d , ", arr[i]);
	printf("\n");

	return 0;
}
