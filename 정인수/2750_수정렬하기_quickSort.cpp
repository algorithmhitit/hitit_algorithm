//수정렬하기_quickSort
//2750번
//https://www.acmicpc.net/problem/2750
//문제풀이방법
//quickSort
#include <stdio.h>

class Sort {
private:
    int a[1000];
    int size;
public:
    void getSize(int);
    int returnSize();
    void getArr(int, int);
    void quickSort(int, int);
    void printfArr();
};

void Sort::getSize(int size){
    this->size = size;
}

int Sort::returnSize() {
    return size;
}

void Sort::getArr(int index, int value){
    a[index] = value;
}

void Sort::quickSort(int left,int right) {
    //여기에 소팅부분을 멋지게 구현해주고
    int pivot,temp;
    int low=left+1;
    int high = right;
    pivot = a[left];
    if(left < right){
        while(low<=high){
            while(a[low]<pivot){
                low++;
                //printf("low = %d\n",low);
            }
            while(a[high]>pivot){
                high--;
                //printf("high = %d\n",high);
            }
            if(low<high){
                temp = a[high];
                a[high] = a[low];
                a[low] = temp;
            }
        }
        temp = a[left];
        a[left] = a[high];
        a[high] = temp;
        
        //printfArr();
        
        int pivotIndex = high;
        quickSort(left,pivotIndex-1);
        quickSort(pivotIndex+1,right);
    }
}

void Sort::printfArr(){
    for(int i=0; i<size;i++){
        printf("%d\n",a[i]);
    }
    printf("\n");
}

int main () {
    int size,value;
    Sort sort;
    scanf("%d",&size);
    sort.getSize(size);

    for(int i=0;i<size;i++){
        scanf("%d",&value);
        sort.getArr(i,value);
    }

    //sort.printfArr();

    sort.quickSort(0,sort.returnSize()-1);

    sort.printfArr();
}
