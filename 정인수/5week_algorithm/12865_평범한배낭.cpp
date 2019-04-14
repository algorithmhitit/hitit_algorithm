//평범한배낭
//12865번
//https://www.acmicpc.net/problem/12865

#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct article {
    int w;
    int v;
};

int findMaxValue(article[],int,int);

int main (){
    int articleNum;//상품
    int maxWeight;//무게
    int ans=0;
    struct article a[100000];//a[][0]은 무게, a[][1]은 가치 value를 가진다.

    scanf("%d %d", &articleNum, &maxWeight);
    for(int i=0;i<articleNum;i++){
        scanf("%d %d", &a[i].w, &a[i].v);
    }

    ans = findMaxValue(a, articleNum, maxWeight);

    printf("%d", ans);
    return 0;
}

int findMaxValue(article a[],int articleNum , int maxWeight){
    int weight[100001] = {0};
    for(int i=0;i<articleNum;i++){
        for(int j=maxWeight;j>=a[i].w;j--){
            if((weight[j-a[i].w]+a[i].v)>=weight[j]){
                weight[j] = weight[j-a[i].w]+a[i].v;
            }
        }
    }
    return weight[maxWeight];
}