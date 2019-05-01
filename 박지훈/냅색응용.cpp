#include <stdio.h>
#define mad 10001
int max(int i,int j);
bool toggle = false;
int w[101],w2[mad]; //w<10,000 w*c<10,000
int v[101],v2[mad];//v*c<10,000
int c[101]; 
int w3,v3,i1=0;
int dp[mad][2];
int n, k,t=0; //n<100  k<10,000 

int main() 
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &w[i], &v[i],&c[i]);
	}
	for(int i=0;i<n;i++)
	{
		t = t + c[i];
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<c[i];j++)
		{
			w2[i1]=w[i];
			v2[i1]=v[i];
			i1++;
		}
	}
	printf("%d\n",t);
	for (int i = 0; i < t; i++) {
		printf("%d %d\n", w2[i], v2[i]);
	}
	for (int i = 0; i < t; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - w2[i] < 0) dp[j][toggle] = dp[j][!toggle];
			else dp[j][toggle] = max(dp[j][!toggle], dp[j - w2[i]][!toggle] + v2[i]);
		}
		toggle = !toggle;
	}
	printf("%d\n",max(dp[k][toggle], dp[k][!toggle]));
	
}
int max(int i,int j)
{
	if(i>j)
	return i;
	else
	return j;
}
