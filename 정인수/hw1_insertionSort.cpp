//삽입정렬, 오름차순으로 정렬할 때, 배열 내의 원소들의 이동회수를 출력한다.
#include <stdio.h>

void swap(int a[],int i, int j);
int insertion_sort ( int *data, int n );

int main() {
    int n=0;
    int a[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",insertion_sort(a,n));
}

int insertion_sort ( int *data, int n )
{
  int i, j, remember,count=0;
  for ( i = 1; i < n; i++ )
  {
    remember = data[(j=i)];
    count++;
    while ( --j >= 0 && remember < data[j] ){
        data[j+1] = data[j];
        data[j] = remember;
        count++;
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