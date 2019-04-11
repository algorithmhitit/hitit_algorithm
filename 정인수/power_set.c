#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[100]={0,};
int n[100000][100]={0,};
int size[100000]={0,};

int pow_n(int x, int y){
	if(y==0){
		return 1;
	}
	return x*pow_n(x,y-1);
}

void pre_n(int x,int first,int last){
	printf("pre_n x= %d\n",x);
	for(int i=first;i<=last;i++){
		n[i][size[i]] = x;
		size[i]++;
		printf("size[%d] = %d n[%d][%d] = %d \n",i,size[i],i,size[i]-1,x);
	}
}

void powerSet(int i,int count,int arraySize){
	printf("PowerSet i=%d count = %d arraySize = %d\n",i,count,arraySize);
	count--;
	if(count+1 == 0){
		return;
	}

	int first,last;
	
	if(count == 0){
		first = 1;
		last = 1;
	}
	else{	
		first = pow_n(2,count)+1;
		last = pow_n(2,count+1);
	}
	powerSet(i+1,count,arraySize);
	
	printf("a[%d] = %d\n",i,a[i]);
	
	int f=first-1;
	for(int k=0;k<f;k++){
		for(int l=0;l<size[k];l++){
			n[f+k][l] = n[k][l];
			size[f+k]++;
		}
	}
	pre_n(a[i],first-1,last-1);
	
}

void printPowerSet(int s){
	for(int i=0;i<s;i++){
		printf("[");
		for(int j=0;j<size[i];j++){
			printf("%d ",n[i][j]);
		}
		printf("] ");
	}
}

int main () {
	int i=0;
    int size=0;//입력받은 수의 크기
    
    char endCheck;

    do{
        scanf("%d%c",&a[i++],&endCheck);
        size++;
    }while(endCheck == ',');

    printf("i=%d\n",i);
    
    for(int i=0;i<size;i++){
        printf("[%d], ",a[i]);
    }
    printf("\n");
    
    int powerSetSize = pow_n(2,size);
    powerSet(0,size,size);
    printPowerSet(powerSetSize);
    printf("\n");
    return 0;
}