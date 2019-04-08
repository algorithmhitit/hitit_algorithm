#include<stdio.h>

int a[320];
int c;
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int n=1;n<=N;n++)
	{
	if(n==1)
	{
		a[1]= a[1];
	}else if(n==2)
	{
		c++;
		a[2]= a[1]+a[2];
	}else if(n==3)
	{
		if(a[2]<a[3])
		{
			a[3]= a[1]+a[3];
		}else
		{
			a[3]=a[2];
		}
	}else if(n>=3)
	{
		if(a[n-1]>a[n-2]&&c!=1)
		{
			c++;
			a[n]= a[n-1]+a[n];
		}else 
		{
			c=0;
			a[n]= a[n-2]+a[n];
		}
	}
	}
	printf("%d",a[N]);
}

