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
	
	long long left =0;
	long long right = 1000000000000;
	long long mid=0;
	long long cBalloonNum=0;
	
	while(left < right){
		cBalloonNum = 0;
		mid = (left + right)/2;
		for(int i=0;i<staffNum;i++){
			cBalloonNum += mid/bs[i];
		}
		if(cBalloonNum >= ballonNum){
			right = mid;
		}
		else {
			left = mid+1;
		}
	}
	
	printf("%lld",left);
	
	return 0; 
}
