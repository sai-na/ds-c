#include<stdio.h>
int main()
{
	int arr[50],n,i,j,temp;
	printf("Enter the Number of terms in the array : ");
	scanf("%d",&n);
	printf("\nEnter the array ELements \n");
	for(i=0;i<n;i++)
	{
	printf("\nElement[%d] : ",i+1);
	scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
	for(j=0;j<n-i-1;j++)
	{
	if(arr[j]>arr[j+1])
	{
	temp=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=temp;
	}
	}
	}
	printf("\nThe Sorted Array is : ");
	for(i=0;i<n;i++)
	{
	printf("\n%d",arr[i]);
	}
	return 0;
}