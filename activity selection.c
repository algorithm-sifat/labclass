#include<stdio.h>
#include<stdlib.h>
#define Size 100
#include<time.h>
 void activity(int a[],int b[],int n)
{
    int i=0,j;
    printf("THE  activities are \nA %d\n",a[i]);

    for (j=0 ; j<=n; j++)
    {
        if (a[j]>=b[i])
        {
            printf("A %d\n",a[j]);
            i=j;
        }

    }
}


int main ()
{
    int n,i;

    int a[Size],b[Size];
    printf("Enter the size of array\n");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter element of array 1 A%d \n",i+1);
        scanf("%d",&a[i]);
        printf("Enter element of array 2 A %d\n",i+1);
        scanf("%d",&b[i]);
    }

    activity(a,b,n);
    return 0;

}
