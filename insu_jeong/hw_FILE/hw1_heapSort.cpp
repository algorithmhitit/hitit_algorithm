//heapSort
#include <stdio.h>

void buildHeap(int a[],int n);//배열 a를 heap으로 만드는 함수
void heapify(int a[],int k, int n);//max-heap을 배열의 제일 뒤로 옮겨준다.
void heapSort(int a[], int n);
void heapify_n(int a[],int k, int n);

int swpCount=0;

int main() {
    int n;//배열의 크기를 입력받는다.
    int a[10000];//최대 배열의 개수는 10000개이다.
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    heapSort(a,n);

    printf("%d",swpCount);

    return 0; 
}

void heapSort(int a[], int n){
    int tmp;
    buildHeap(a,n);
    for(int i=n;i>=2;i--){
        tmp = a[1];
        a[1] = a[i];
        a[i] = tmp;
        heapify(a,1,i-1);
    }
}

void buildHeap(int a[],int n){
    for(int i=n/2;i>=1;i--){
        heapify_n(a,i,n);
    }
}

void heapify_n(int a[],int k, int n) {
    int left = 2*k;
    int right = 2*k+1;
    int bigger;
    int tmp;
    if(right<=n){
        if(a[left] > a[right]){
            bigger = left;
        }
        else{
            bigger = right;
        }
    }
    else if(left<=n){
        bigger = left;
    }
    else return;

    if(a[bigger] > a[k]) {
        tmp = a[bigger];
        a[bigger] = a[k];
        a[k] = tmp;;
        heapify(a,bigger,n);
    }
}

void heapify(int a[],int k, int n) {
    int left = 2*k;
    int right = 2*k+1;
    int bigger;
    int tmp;
    if(right<=n){
        if(a[left] > a[right]){
            bigger = left;
        }
        else{
            bigger = right;
        }
    }
    else if(left<=n){
        bigger = left;
    }
    else return;

    if(a[bigger] > a[k]) {
        swpCount++;
        tmp = a[bigger];
        a[bigger] = a[k];
        a[k] = tmp;;
        heapify(a,bigger,n);
    }
}
