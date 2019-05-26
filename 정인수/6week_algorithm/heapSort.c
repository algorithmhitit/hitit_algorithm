#include <stdio.h>
#include <stdlib.h>

/* Definition of Int List */
typedef struct IntList   IL;   /* */
typedef struct IntList* PIL;   /* */

struct IntList {
   int h;
   PIL t;//IntList* 포인터
};

PIL IL_cons(int, PIL); /* ::  IL construct   */

////////heapSort funtion//////////////////
void swap(int a,int b,int arr[]);
void bubbleDown(int i,int arr[]);
void heapify(PIL il, int arr[],int n);
int listSize(PIL il,int size);
void arrayToList(int arr[],PIL il,int size,int i);
PIL heapSort(PIL il,int arr[],int i);
/////////////////////////////////////////////////

void IL_print(PIL);

int main()
{
    PIL set = (PIL)malloc(sizeof(IL)),test = (PIL)malloc(sizeof(IL));;
    set->t = NULL;
    test->t = NULL;
    set->t = IL_cons(2, IL_cons(1, IL_cons(3, IL_cons(5, IL_cons(4, IL_cons(7, IL_cons(6, NULL))))))); 
    int arr[100] = {0,};
    set = heapSort(set,arr,1);
	IL_print(set->t);
    //heapify(set,arr,1);
	/*for(int i=0;i<=5;i++){
        arr[i] = i;
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    arrayToList(arr,test,5,1);
    IL_print(test->t);*/
    return 0;
}

void swap(int a, int b, int arr[]){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void bubbleDown(int i,int arr[]){
    int i2 = i/2;
    if(arr[i]<arr[i2] && i>1){
        swap(i,i2,arr);
        bubbleDown(i2,arr);
    }
}

int listSize(PIL il,int size){
    PIL tmp = il;
    tmp->t;
    while(tmp->t != NULL){
        tmp = tmp->t;
        size++;
    }
    return size;
}

void heapify(PIL il, int arr[],int n){
    PIL tmp = il->t;
    if(tmp != NULL){
        arr[n] = tmp->h;
        bubbleDown(n,arr);
        heapify(tmp,arr,n+1);
    }
}

void arrayToList(int arr[],PIL il,int size,int i){
    //PIL tmp = il->t;
    if(size > 0){
        PIL pintlist = (PIL)malloc(sizeof(IL));
        //IL_cons(arr[i],il);
        //il = pintlist;
        il->t = pintlist;
        pintlist->t = NULL;
        pintlist->h = arr[i];
        printf("pintlist->h : %d\n",pintlist->h);
        arrayToList(arr,pintlist,size-1,i+1);
    }
}

PIL heapSort(PIL il,int arr[],int i){
    PIL tmp = il;
    int size = listSize(il,0);
    printf("size = %d\n",size);
    if(size != 0){
        heapify(il,arr,1);
        arrayToList(arr,tmp,size,1);
        tmp = heapSort(tmp->t,arr,i+1);
    }
    return il;
}

PIL IL_cons(int x, PIL intlist)          /* ::  IL construct   */
{
    PIL pintlist = (PIL)malloc(sizeof(IL));
    pintlist->t = intlist;
    pintlist->h = x;
    return pintlist;
}

void IL_print(PIL intlist)
{
    if(intlist == NULL){
        return;
    }
    else {
        if(intlist->h != 0){
            printf("%d ",intlist->h);
        }
        IL_print(intlist->t);
        return;
    }
}