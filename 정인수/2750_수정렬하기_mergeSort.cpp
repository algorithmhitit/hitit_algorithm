//수정렬하기_mergeSort
//2750번
//https://www.acmicpc.net/problem/2750
//문제풀이방법
//mergeSort
#include <stdio.h>

class Sort {
private:
    int a[1000];
    int size;
public:
    Sort();
    ~Sort();
    void getSize(int);
    int returnSize();
    void getArr(int, int);
    void merge(int,int,int);
    void mergeSortingArr(int, int);
    void printfArr();
};

Sort::Sort(){
    int size =0;
    for(int i=0;i<1000;i++){
        a[i]={0};
    }
}

Sort::~Sort(){}

void Sort::getSize(int size) {
    this->size = size;
}

int Sort::returnSize() {
   return size; 
}

void Sort::getArr(int index,int value) {
    this->a[index] = value;
}

void Sort::printfArr() {
    for(int i = 0 ; i < size ; i++) {
        printf("%d\n", a[i]);
    }
}

void Sort::merge(int front, int middle, int last) {
    int temp[1000] = {0,};
    int front1 = front;
    int last1 = middle;
    int front2 = middle + 1;
    int last2 = last;
    for(int i=front;i<=last;i++){
        if(front1>last1){
            temp[i] = a[front2];
            front2++;
        }
        else if (front2>last2){
            temp[i] = a[front1];
            front1++;
        }
        else if(a[front1]<a[front2]){
            temp[i] = a[front1];
            front1++;
        }
        else if(a[front1]>=a[front2]){
            temp[i] = a[front2];            front2++;
        }
    }

    for(int i=front;i<=last;i++){
        a[i] = temp[i];
    }

    return;
}

void Sort::mergeSortingArr(int front, int last){
    int middle=(front+last)/2;
    if(front!=last){
        mergeSortingArr(front,middle);
        mergeSortingArr(middle+1,last);
    }
    merge(front,middle,last);
    
}

int main () {
    int size;
    int value;
    Sort sort;

    scanf("%d",&size);
    sort.getSize(size);

    for(int i=0;i<size;i++){
        scanf("%d",&value);
        sort.getArr(i,value);
    }

    sort.mergeSortingArr(0,size-1);

    sort.printfArr();

    return 0;
}