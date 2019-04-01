#include<stdio.h>
 
int main()
{
	int N,S,t=0;  //갯수,제한,합 
	//int c=0;//숫자길이
	scanf("%d %d",&N,&S);
	int a[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	//a[0]부터a[N]까지 터해서 아니면,0
	for(int i=0;i<N;i++)
	{
		t=t+a[i];
	}
	if(t<S)
	{
		printf("0");
		return 0;
	}
	t=0;
	int c=0;
	//1번째 에선 1,2,3,4,5,6...N,아니면 카운드 +1
	for(;c<N-1;c++)
	{
		for(int i=0;i<N-c;i++)
		{
			for(int j=i;j<=i+c;j++)
			{
				
			t=t+a[j];
			}
			printf("%d\n",t);
			if(t>=S)
			{
				break;
			}
			t=0;
		}
		if(t>=S)
		{
			break;
		}
	}	
	printf("%d",c+1);
}
 
