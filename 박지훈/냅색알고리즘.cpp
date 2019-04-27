#include <stdio.h>
#define mad 100001
int max(int i,int j);
bool toggle = false;
int w[101];
int v[101];

int dp[mad][2];
int n, k;

int main() 
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {				
			if (j - w[i] < 0) dp[j][toggle] = dp[j][!toggle];
			else dp[j][toggle] = max(dp[j][!toggle], dp[j - w[i]][!toggle] + v[i]);			
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
