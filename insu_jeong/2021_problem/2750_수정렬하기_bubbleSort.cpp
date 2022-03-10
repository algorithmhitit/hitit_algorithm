//수정렬하기_bubbleSort
//2750번
//https://www.acmicpc.net/problem/2750
//문제 풀이 방법
//bubble sort

#include <stdio.h>

void bubbleSort(int size,int a[]){
    int temp;
    for(int j=size-1;j>0;j--){
        for(int i=0;i<=j-1;i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}

int main() {
    int size=0;
    int a[1000];
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d", &a[i]);
    }

    bubbleSort(size,a);

    for(int i=0; i<size; i++){
        printf("%d\n",a[i]);
    }
}