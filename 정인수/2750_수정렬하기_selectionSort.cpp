//수정렬하기_selectionSort
//2750번
//https://www.acmicpc.net/problem/2750
//문제 풀이 방법
//selection sort
#include <stdio.h>

int selectionSort(int size, int a[]){
    int temp=0;
    int minIndex;
    for(int i=0;i<size;i++){
        minIndex = i;
        for(int j=i;j<size;j++){
            if(a[j] < a[minIndex]){
                minIndex=j;
            }
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

int main () {
    int size=0;
    int a[1000];
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    selectionSort(size,a);
    for(int i=0;i<size;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}