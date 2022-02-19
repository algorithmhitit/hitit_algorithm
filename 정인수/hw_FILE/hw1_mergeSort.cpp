//mergeSort 알고리즘 수업 homework 1
#include <stdio.h>

int count=0;
int temp[10000];
int a[10000];

void mergeSort(int a[],int p,int r);
void merge(int a[],int p,int q, int r);

int main () {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }    
    
    mergeSort(a,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    } 
    printf("%d", count);

    return 0;
}

void mergeSort(int a[],int p,int r){
    int q;
    //count++;//19
    if(p<r){
        q=(p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
    }

}

void merge(int a[], int p, int q, int r){
    int i=p;//i는 mergeSort에서 나눈 정렬된 배열의 앞부분의 위치를 알려주는 index이다.
    int j=q+1;//j는 mergeSort에서 나눈 정렬된 배열의 뒷부분의 현재 위치를 알려주는 index이다.
    int t=0;//temp의 index를 가르킨다.
    //count++;//9
    while(i<=q && j<=r){//i와 j가 자신의 배열의 뒷부분을 넘어가지 않는선에서 while문을 돌려줌
        //count++;//23
        if(a[i] < a[j]){
            count++;//7
            temp[t++] = a[i++];//temp의 index와 a의 index를 대입이 완료된후 +1해준다.
        }
        else if(a[i] == a[j]){
            count++;//5
            temp[t++] = a[j++];//temp의 index와 a의 index를 대입이 완료된후 +1해준다.
        }
        else if(a[i] > a[j]) {
            count++;//11
            temp[t++] = a[j++];
        }
        else {
            printf("Error: Someting wrong in merge\n");
        }
    }
    while(i<=q){
        temp[t++] = a[i++];
    }
    while(j<=r){
        temp[t++] = a[j++];
    }
    //t와 i에 들어있는 index의 위치값을 초기화 시켜준다.
    i=p;
    t=0;
    //결과를 a[p......r]에 저장
    while(i<=r){
        a[i++] = temp[t++];
    }
}