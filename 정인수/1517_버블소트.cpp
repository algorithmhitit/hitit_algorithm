//버블소트
//1517번
//https://www.acmicpc.net/problem/1517
//문제 풀이 방법
//bubble sort -> 아님
//
#include <stdio.h>
#include <algorithm>
//using namespace std;

struct sortData{
    int index;//배열의 인덱스 값 저장
    int data;//배열의 값 저장
};

struct sortData a[500000];
struct sortData b[500000];//정렬된 a

int bubbleSortCount(int size){
    int temp;
    int sum=0;
    for(int i=0;i<size-1;i++){
        if(a[i].data>a[i+1].data){
        	sum=sum+size-1-i-/*�ڽ� �տ� �ִ� �ڱ⺸�� ū��*/;
        }
    }
    return sum;
}

bool cmp(const sortData &p1, const sortData &p2){
    return p1.data<p2.data;
}

int main() {
    int size=0;
    
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d", &a[i].data);
        a[i].index=i;
        b[i].index=i;
        b[i].data = a[i].data;
    }

    std::stable_sort(b,b+size,cmp);
    
    for(int i=0;i<size;i++){
    	a[b[i].index].index=i;
	}

    printf("%d",bubbleSortCount(size));

    for(int i=0; i<size; i++){
        printf("%d\n",a[i].data);
    }
}
