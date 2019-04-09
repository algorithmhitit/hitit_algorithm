#include <stdio.h>
#include <math.h>

int main () {
    int i=0;
    int a[100];
    int n=0;//입력받은 수의 크기
    char endCheck;
    do{
        scanf("%d%c ",&a[i++],&endCheck);
    }while(endCheck == ',');

    printf("i=%d\n",i);
    
    for(int i=0;i<n;i++){
        printf("[%d], ",&a[i]);
    }
    return 0;
}