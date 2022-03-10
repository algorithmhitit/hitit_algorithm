//버블소트
//1517번
//https://www.acmicpc.net/problem/1517
//
//bubble sort  -> merge소트로 계산해서 소팅으로 이동한 거리 만큼의 차이를 count에 추가시키는방법으로 풀어보자 
//답은 long long 으로 하지않으면 정상적으로 작동하지 않는다.
#include <stdio.h>

struct sortData{
    int index;
    int data;
};

struct sortData a[500000];
struct sortData b[500000];
long long count;

int bubbleSortCount(int size){
    int temp;
    int sum=0;
    for(int i=0;i<size-1;i++){
        if(a[i].data>a[i+1].data){
        	sum=sum+size-1-i;
        }
    }
    return sum;
}

void merge(sortData a[],int first,int middle,int last) {
    //정렬된 배열 왼쪽과 오른쪽을 임시로 b에 저장하며 정렬해준 후에 a로 정렬된 배열을 옮겨준다.
    int index=first;
    int f1=first,l1=last,m1 = middle;
    //printf("first : %d  last : %d\n",first,last);
    while(index <= last){
        if(middle+1 > l1){
            b[index].data = a[first].data;
            first++;
        }
        else if(first > m1) {
            b[index].data = a[middle+1].data;
            middle++;
        }
        else if(a[first].data > a[middle+1].data){
            b[index].data = a[middle+1].data;
            count = count + middle+1-index;
            middle++;
            //printf("in merge : count  = %d \n",count);
            //printf("first : %d first.data : %d middle : %d middle+1 : %d a[middle+1].data: %d\n"
            //, first, a[first].data , middle - 1, middle, a[middle].data);
        }
        else if(a[first].data <= a[middle+1].data){
            b[index].data = a[first].data;
            first++;
            //printf("first : %d first.data : %d middle : %d middle+1 : %d a[middle+1].data: %d\n"
            //, first-1, a[first-1].data , middle, middle+1, a[middle+1].data);
        }
        else {
            printf("ERROR: merge fail!\n");
        }
        index++;
    }
    for(int i=f1;i<=l1;i++){
        a[i].data = b[i].data;
        //printf("a[%d] : %d\n",i,a[i].data);
    }
}

void mergeSort(sortData a[], int first, int last){
    int middle = (last + first) /2;
    if(first<last){
        mergeSort(a,first,middle);
        mergeSort(a,middle+1,last);
        merge(a,first,middle,last);
    }
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

    mergeSort(a,0,size-1);

    for(int i=0;i<size;i++){
    	a[b[i].index].index=i;
	}

    printf("%lld",count);
    //printf("count = %lld\n",count);

    /*for(int i=0; i<size; i++){
        printf("%d\n",a[i].data);
    }*/
}