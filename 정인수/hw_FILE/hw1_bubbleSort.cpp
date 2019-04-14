//오름차순으로 정렬할 때, 배열 내의 원소들 사이의 교환 회수를 출력한다.
#include <stdio.h>

int bubbleSort(int a[], int n);
int swap(int a[],int i,int j);

int main(){
    int n;//배열의 크기를 입력받는다.
    int a[10000];//최대 배열의 개수는 10000개이다.
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",bubbleSort(a,n));
    
    return 0;
}

//bubbleSort를 통해 얼만큼의 swap이 일어났는지 return 해주고 오름차순으로 정렬해주는 함수
int bubbleSort(int a[],int n){
    int swapCount=0;
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                swap(a,j,j+1);
                swapCount++;
            }
        }
    }

    return swapCount;
}

//입력받은 a배열상의 index i,j의 값을 교환하여 배열에 적용하여 주는 함수
int swap(int a[], int i, int j) {
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}