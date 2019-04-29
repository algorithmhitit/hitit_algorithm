#include<stdio.h>

int N,x;//종류 , 길이    
int  L[101],C[101];//수량,갯수 짧은순 
	
int add,count=0;
	

int c(int i,int j);
int main()
{
	//파이프 길이,수량 알고있을 때   
	//x만큼의 길이 만드는 방법 수는?  방법수 <2,147,483,647
	
	scanf("%d %d",&N,&x);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&L[i],&C[i]);
	}
	/*for(int i=0;i<=C[2];i++)
	{
		for(int j=0;j<=C[1];j++)
		{
			for(int k=0;k<=C[0];k++)
			{
				add = L[2]*k+L[1]*j+L[0]*i;
				if(add==x)
				{
					count++;
				}
			}
		}
	}*/
	
	c(0,0);
	printf("%d\n",add);
	//printf("%d",count);
	
}
int c(int i,int j) 
{
	i++;
	if(i<N)
	{
		for(int k=0;k<C[i];k++)
		{
			c(i,k);
		}
		
	}
	return L[i]*j;
}
