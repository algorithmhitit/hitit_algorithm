//삽입정렬, 오름차순으로 정렬할 때, 배열 내의 원소들의 이동회수를 출력한다.
#include <stdio.h>

int insertionSort(int a[],int n);
void swap(int a[],int i, int j);

int main() {
    int n=0;
    int a[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",insertionSort(a,n));
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int insertionSort(int a[], int n){
    int count=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]>a[i]){
                swap(a,j,i);
            }
            else count++;
        }
        
    }
    return count;
}

void swap(int a[],int i, int j){
    int temp =a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}