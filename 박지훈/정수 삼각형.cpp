#include<stdio.h>
int arr[501][501]={0,};
int max(int i,int j);
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int add;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
				arr[i][j] = arr[i][j] + max(arr[i-1][j-1],arr[i-1][j]);
		}
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("arr[%d][%d]",i,j);
		}
		printf("\n");
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}*/
	int arrmax=arr[n][1];
	for(int i=1;i<=n;i++)
	{
		if(arr[n][i]>arrmax)
		arrmax=arr[n][i];
	}
	printf("%d",arrmax);
}
int max(int i,int j)
{
	if(i>j)
	return i;
	else
	return j;
}

