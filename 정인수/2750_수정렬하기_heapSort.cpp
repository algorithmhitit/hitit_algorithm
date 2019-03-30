//수정렬하기_heapSort
//2750번
//https://www.acmicpc.net/problem/2750
//문제 풀이 방법
//heap sort
#include <stdio.h>

void printfArr(int a[],int size){
    for(int i=0;i<size;i++){
        printf("%d\n",a[i]);
    }
}

void swap(int a[],int i,int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void insertHeap(int a[],int val){

}

int deleteHeap(int a[],int heapIndex){
    int temp = a[0];
    int i=0;
    a[0] = a[heapIndex];
    a[heapIndex] = temp;
    if(a[2*i] > a[2*i+1]){
        if(a[i]>a[2*i]){
            swap(a,i,2*i);
        }
    }
    else{
        if(a[i]>a[2*i+1]){
            swap(a,i,2*i+1);
        }
    }
    return a[heapIndex];
}

void heapSort(int a[],int size) {
    for(int i=0;i<size;i++){
        insertHeap(a,a[i]);
    }
    for(int i=size-1;i>=0;i--){
        a[i] = deleteHeap(a,i);
    }
}

int main () {
    int size;
    int a[1000];
    scanf("%d",&size);
    for(int i=0; i<size;i++){
        scanf("%d",&a[i]);
    }

    heapSort(a,size);

    printfArr(a,size);

    return 0;
}