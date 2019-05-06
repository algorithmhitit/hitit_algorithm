//풍선공장
//15810번
//https://www.acmicpc.net/problem/15810
#include <stdio.h>

int staffNum=0,ballonNum;
int ans=0;
int bs[1000000];//풍선 부는 속도 ballon speed 

int main() {
	scanf("%d %d",&staffNum,&ballonNum);
	for(int i=0;i<staffNum;i++){
		scanf("%d", &bs[i]);
	}
	
	int left =0;
	int right = 1000000000;
	int mid=0;
	int res =0;
	
	while(left < right){
		ans = 0;
		mid = (left + right)/2;
		for(int i=0;i<staffNum;i++){
			ans = ans + mid/bs[i];
		}
		if(ans >= ballonNum){
			right = mid;
		}
		else {
			left = mid+1;
		}
	}
	
	//ans = find(0,1000000);
	//printf("%d",ans);
	
	printf("%d",right);
	
	return 0; 
}