//전국시대
//15809번
//https://www.acmicpc.net/problem/15809
//union find로 풀었는데 어떻게 풀렸는지 모르겠다.
#include <stdio.h>
#include <algorithm>

struct nation {
	int army;
	int checkAlliance;
	struct allian *alliance;
};

struct allian {
	int num;
	int totalArmy;
	int numOfAlliance;
	struct allian *alliance;
}; 

struct nation N[100000];
struct allian A[100000];

int numOfNation;
int numOfEvent;
int state;
int nationA;
int nationB;

bool cmp(int a, int b) {
	return a<b;
}

int find(int x) {
	if(N[x].alliance->num == x) {
		return x;
	}
	else {
		return N[x].alliance->num = find(N[x].alliance->num);
	}
}

void unionA(int x, int y){
    // 각 원소가 속한 트리의 루트 노드를 찾는다.
    x = find(x);
    y = find(y);
	
	N[y].alliance->num = N[x].alliance->num;
    A[y].alliance = A[x].alliance;
}

void fightAge(int state, int a, int b) {
	//동맹을 할때
	a--;//배열의 시작값에 맞춰주기 
	b--;
	a=find(a);
	b=find(b);
	if(state == 1){
		//동맹을 한다.
		N[a].alliance->totalArmy = N[a].alliance->totalArmy + N[b].alliance->totalArmy;//국가 간의 동맹으로 인한 병력수 통합 
		N[b].alliance->totalArmy = 0;
		unionA(a,b);//동맹을 일치 시켜주었다. 
		A[a].numOfAlliance=A[a].numOfAlliance + A[b].numOfAlliance;//a 국가를 주축으로한 동맹국들의 숫자
		
		numOfNation--;//한개의 동맹도 큰들에서 보면 나라 1개로 볼수 있으니 국가의 수는 1개만 줄어든다. 
		
		return; 
	}
	//전쟁을 할때 
	else if(state == 2){
		//전쟁에서 이겼을때
		if(N[a].alliance->totalArmy > N[b].alliance->totalArmy){
			N[a].alliance->totalArmy = N[a].alliance->totalArmy - N[b].alliance->totalArmy;//국가 간의 동맹으로 인한 병력수 통합 
			N[b].alliance->totalArmy = 0;
		}
		else if(N[a].alliance->totalArmy == N[b].alliance->totalArmy){
			N[a].alliance->totalArmy = N[a].alliance->totalArmy - N[b].alliance->totalArmy;
			N[b].alliance->totalArmy = 0;
			numOfNation = numOfNation - 2;//2국가 2개가 싸워서 망했기 때문에 2개를 빼주었다.
			return;
		}
		else {
			N[a].alliance->totalArmy = N[b].alliance->totalArmy - N[a].alliance->totalArmy;
			N[b].alliance->totalArmy = 0;
		}
		
		unionA(a,b);//동맹을 일치 시켜주었다. 
		//A[a].numOfAlliance=A[a].numOfAlliance + A[b].numOfAlliance;//a 국가를 주축으로한 동맹국들의 숫자
		numOfNation--;//한개의 동맹도 큰들에서 보면 나라 1개로 볼수 있으니 국가의 수는 1개만 줄어든다. 
		
		
		//전쟁에서 비겼을 때, 두나라 모두 멸망 
	}
	//else
	//	printf("mistatke state : fightAge Funtion\n");

	return;
}

int main ()
{
	scanf("%d %d",&numOfNation,&numOfEvent);
	int firstNation=numOfNation;
	
	for(int i=0;i<numOfNation;i++){
		scanf("%d", &N[i].army);
	}
	
	for(int i=0; i<numOfNation; i++){
		A[i].totalArmy = N[i].army;
		A[i].numOfAlliance = 1;
		N[i].alliance = &A[i];
		A[i].alliance = &A[i];
		A[i].num = i;
	}
	
	int temp1[100000];
	int temp2[100000];
	int temp3[100000];
	
	for(int i=0;i<numOfEvent;i++){
		scanf("%d %d %d",&temp1[i], &temp2[i], &temp3[i]);
	}
	
	
	for(int i=0;i<numOfEvent;i++){
		fightAge(temp1[i], temp2[i], temp3[i]);
	}
	
	printf("%d\n",numOfNation);
	
	//처음 국가의 개수만큼 돌고 병사가 0인 동맹의 병사는 출력하지 않는다. 
	int count = 0;
	int temp[100000];
	for(int i=0;i<firstNation;i++){
		if(A[i].totalArmy != 0){
			temp[count] = A[i].totalArmy;
			count++;
		}
	}
	
	//temp 소팅이 필요하다. 
	std::stable_sort(temp,temp+count,cmp);
	
	for(int i=0; i <count ; i++){
		printf("%d ",temp[i]);
	}
	
	return 0;
}