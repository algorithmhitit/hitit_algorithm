//quickSort
#include <stdio.h>
int a[10000];
int count=0;

int partition(int a[],int p,int r)
{

    int x = a[r];
    int temp;
    int i = p - 1;
    for(int j=p;j<r;j++){
        if(a[j] <= x) {
            count++;
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            //printf("a[j] = %d, x = %d, p = %d, r = %d q = %d\n",a[j],x, p, r, i+1);
        }
    }
    count++;
    temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    //printf("p = %d, r = %d q = %d\n", p, r, i+1);
    return i+1;
}

void quickSort(int a[], int p, int r){
    if(p<r){
        int q= partition(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }
}

int main() {
    int n=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);

    /*for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }*/

    printf("%d", count);

    return 0;
}