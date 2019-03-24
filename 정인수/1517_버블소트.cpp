//버블소트
//1517번
//https://www.acmicpc.net/problem/1517
//문제 풀이 방법
//bubble sort -> 아님
//
#include <stdio.h>

int a[500000];

int bubbleSort(int size,int a[]){
    int temp;
    int count;
    for(int j=size-1;j>0;j--){
        for(int i=0;i<=j-1;i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int size=0;
    
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d", &a[i]);
    }

    printf("%d",bubbleSort(size,a));

    /*for(int i=0; i<size; i++){
        printf("%d\n",a[i]);
    }*/
}