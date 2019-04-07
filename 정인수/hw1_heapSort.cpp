//heapSort


void bubbleHeap(int a[],int n);//배열 a를 heap으로 만드는 함수
void heapify(int a[],int k, int n);//max-heap을 배열의 제일 뒤로 옮겨준다.
void heapSort(int a[], int n);

int main() {

   return 0; 
}

void heapSort(int a[], int n){
    if(n>0){
        heapify(a,0,n);
        heapSort(a,n-1);
    }
}

