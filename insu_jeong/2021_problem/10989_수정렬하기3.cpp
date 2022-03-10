//수정렬하기
//10989번
//https://www.acmicpc.net/problem/10989
//문제풀이 counting sort를 사용한풀이

#include  <stdio.h>

int main () {
    int a[10000] = {0,};
    int size;
    int temp;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&temp);
        a[temp-1]++;
    }
    
    for(int i=0;i<10000;i++){
        if(a[i]!=0){
            for(int j=0;j<a[i];j++){
                printf("%d\n",i+1);
            }
        }
    }
    return 0;
}