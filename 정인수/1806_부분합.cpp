//부분합 
//1806번
//https://www.acmicpc.net/problem/1806
//front와 last를 사용한 투포인터를 이용하여 해결하였다. 조건으로는 while문이 front가 last를 넘어갔을때 정지하도록 하였고 last가 배열 size의 끝부분에 들어갔을때 예외처리를 해주어서
//수열의 합의 최소크기를 구하는 문제였기 때문에 문제 중간 중간마다 last-front+1을 사용하여 size를 구하고 min 최소값에 저장해주어서 출력했다. 

//front 빼줄때 빼주는 연산을 front ++; 하기전에 해줘야함 어쩐지 계속 틀리더라
#include <stdio.h>

int N[100000];	//숫자가 들어갈 수열의 배열 
int goal = 0;		//최소길이를 구하는데 기준이 되는 수 

int main() {
	int front=0,last=0;//수열의 처음과 끝을 나타내는 포인터
	int size=0;//수열의 크기 
	int sum=0; //지금까지 더한 수들의 합
	int curSize=0;	//현제까지 합한 수들의 크기 
	int anw=0;	//최소 사이즈의 크기를 저장하는 변수 
	int temp=123456;
	int min=123456;
	
	
	scanf("%d %d",&size,&goal);
	for(int i=0;i<size;i++){
		scanf("%d",&N[i]);
	}
	
	int i=0;
	sum=N[0];
	
	while(front<=last){
		if(last<size-1){
			if(front == last) {
				if(goal <= sum){
					temp = last - front + 1;
					sum = sum - N[front];
                    front++;
				}
				else if (goal > sum) {
					last++;
					sum=sum+N[last];
				}
			}
			else {
				if(goal <= sum) {
					temp = last - front + 1;
					sum = sum - N[front];
                    front++;
				}
				else if(goal > sum) {
					last++;
					sum=sum+ N[last];
				}
			}
		}
		else if(last == size - 1){
			if(front == last) {
				if(goal <= sum){
					temp = last - front + 1;
				}
				front++;//종료조건으로 설정했다.
			}
			else if(goal <= sum){
				temp = last - front + 1;
				sum = sum - N[front];
                front++;
			} 
			else if(goal > sum){
				front++;//종료조건으로 설정했다. 계속 늘어나면 종료된다. 
			}
		}
		
		if(min > temp) {
			min = temp;
		}
	}
	
	if(min == 123456){
		min = 0;
	}
	printf("%d",min);
	return 0; 
}
