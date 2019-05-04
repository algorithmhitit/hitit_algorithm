//파닭파닭
//14627번
//https://www.acmicpc.net/problem/14627

#include <stdio.h>

int pa[1000000];

int findmin(int dak[],int paNum){
    int min=dak[0];
    for(int i=1;i<paNum;i++){
        if(min > dak[i]){
            min = dak[i];
        }
    }
    return min;
}

int main() {
    int paNum;
    int padakNum;
    int min;
    int num = 0,ans = 0;
    scanf("%d %d",&paNum,&padakNum);
    for(int i=0;i<paNum;i++){
        scanf("%d",&pa[i]);
    }
    min = findmin(pa,paNum);
    for(int i=0;i<paNum;i++){
        num = num+pa[i]/i;
    }

    printf("%d",ans);
    return 0;
}