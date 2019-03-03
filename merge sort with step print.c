#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#define S1 100000
#define S2 5
 void Merge(int *a, int low, int high, int mid)
{

	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}


	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}


	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}



	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
	for (i=low ; i<k; i++)
    {
        printf("%d ",temp[i]);
    }
    printf("\n");
}


void MergeSort(int a[], int low, int high)
{
	int mid,i;
	if (low < high)
	{
		mid=(low+high)/2;
    for (i=low;i<=high;i++)
    {
        printf("%d ",a[i]);

    }
    printf("\n");
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}

int main()
{
	int n, i;
	FILE *f,*f1;
	int arr[S2],arr1[S1];
	clock_t start,end,start1,end1;
    int total;
    struct timeval tv;
    struct timezone tz;
    struct tm *tm;

	for(i = 0; i < S2; i++)
	{
		printf("Enter element ",i+1,": ");
		scanf("%d",&arr[i]);
	}
	gettimeofday(&tv,&tz);
	MergeSort(arr, 0, S2-1);
	tm = localtime(&tv.tv_sec);
	printf("\nSorted Data");
	for (i = 0; i< S2; i++)
        {
             printf(" %d, ",arr[i]);
        }
    printf("\nExecution time for 5 inputs(in millisec): %d millisec\n",tm->tm_sec);
	return 0;
}

