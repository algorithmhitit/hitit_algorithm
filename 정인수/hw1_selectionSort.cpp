#include <stdio.h>

//a는 정렬을 해줄 int형의 배열, n의 정렬할 배열의 크기
int selectionSort(int a[], int n);
void swap(int a[], int maxIndex, int i);

int main () {
    int n=0;
    int a[10000];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",selectionSort(a,n));
    return 0;
}

int selectionSort(int a[], int n){
    int swapCount = 0;
    int maxIndex = 0;

    for(int i = n-1; i > 0; i--){
        maxIndex = 0;
        for(int j=1;j<=i;j++){
            if(a[maxIndex]<a[j]){
                maxIndex = j;
                swapCount++;
            }
        }
        swap(a,maxIndex,i);
    }

    return swapCount;
}

void swap(int a[], int maxIndex, int i){
    int temp =0;
    temp = a[maxIndex];
    a[maxIndex] = a[i];
    a[i] = temp;
    return;
}