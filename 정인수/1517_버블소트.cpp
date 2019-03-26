//버블소트 
//1517번 
//https://www.acmicpc.net/problem/1517
//
//bubble sort -> 못풀었음 

#include <stdio.h>
#include <algorithm>
//using namespace std;

struct sortData{
    int index;
    int data;
};

struct sortData a[500000];
struct sortData b[500000];

int bubbleSortCount(int size){
    int temp;
    int sum=0;
    for(int i=0;i<size-1;i++){
        if(a[i].data>a[i+1].data){
        	sum=sum+size-1-i-/*자신 앞에 있는 자기보다 큰수*/;
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
