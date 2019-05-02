//disjointSet
//친구의 친구는 친구
//union find
//a와 b는 친구, b와 c는 친구, a와 c는 친구
#include <stdio.h>
#include <stdlib.h>

int f(int x,int a[][2]);

int main() {
    int N,M;//n은 마을 사람 수, M은 친구 쌍의 수
    int a[100000][2];
    int x,y;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        a[i][0] = i;
        a[i][1] = 1;
    }
    for(int i=1;i<=M;i++){
        scanf("%d %d", &x, &y);
        if(x<y){
            if(f(y,a) != f(x,a)){
                a[f(y,a)][1] += a[f(x,a)][1];
            }
            a[f(x,a)][0] = f(y,a);
            
        }
        else {
            if(f(y,a) != f(x,a)){
                a[f(x,a)][1] += a[f(y,a)][1];
            }
            a[f(y,a)][0] = f(x,a);
            
        }
    }
    int max=0;
    for(int i=1;i<=N;i++){
        if(max<a[i][1]){
            max = a[i][1];
        }
    }
    printf("%d",max);
}

int f(int x, int a[][2]){
    while(a[x][0] != x){
        x = a[x][0];
    }
    return x;
}