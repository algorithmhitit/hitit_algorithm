//내려가기
//2096번
//https://www.acmicpc.net/problem/2096
//1번째 2번째 3번째 경로에서의 최소/최대값을 계속 구해주고 마지막 줄에서의 최소/최대 값을 출력해준다.
//다이나믹 프로그래밍
//배열에서 a[0]번째를 사용했기 때문에 배열을 a[100001]로 늘려줘야 했다.
#include <stdio.h>

int a[100001][3];

int findSmallScore(int size){
    int smallScore;
    int sum[100001][3] ={0,};
    int anw;
    for(int i=1;i<=size;i++){
        //sum[i][0]값의 최소값 구하기 이전 경로의 최솟값들의 합과 현재 경로의 값의 합을 비교
        if(sum[i-1][0]<=sum[i-1][1]){
            sum[i][0] = a[i][0] + sum[i-1][0];
        }
        else {
            sum[i][0] = a[i][0] + sum[i-1][1];
        }

        //sum[i][1]값의 최소값 구하기
        if(sum[i-1][0]<=sum[i-1][1] && sum[i-1][0]<=sum[i-1][2]){
            sum[i][1] = a[i][1] + sum[i-1][0];
        }
        else if (sum[i-1][1]<=sum[i-1][0] && sum[i-1][1]<=sum[i-1][2]){
            sum[i][1] = a[i][1] + sum[i-1][1];
        }
        else if(sum[i-1][2]<=sum[i-1][0] && sum[i-1][2]<=sum[i-1][1]) {
            sum[i][1] = a[i][1] + sum[i-1][2];
        }
        else {
            printf("something wrong\n");
        }

        //sum[i][2]값의 최소값 구하기
        if(sum[i-1][1]<=sum[i-1][2]){
            sum[i][2] = a[i][2] + sum[i-1][1];
        }
        else {
            sum[i][2] = a[i][2] + sum[i-1][2];
        }
        //printf("%d %d %d\n", sum[i][0], sum[i][1], sum[i][2]);
    }
    int i=size;
    if(sum[i][0]<=sum[i][1] && sum[i][0]<=sum[i][2]){
        anw = sum[i][0];
    }
    else if (sum[i][1]<=sum[i][0] && sum[i][1]<=sum[i][2]){
        anw = sum[i][1];
    }
    else if(sum[i][2]<=sum[i][0] && sum[i][2]<=sum[i][1]) {
        anw = sum[i][2];
    }    
    //printf("final samllScore is %d\n",anw);

    smallScore=anw;
    return smallScore;
}

int findLargeScore(int size){
    int largeScore;
    int sum[100001][3] ={0,};
    int anw;
    for(int i=1;i<=size;i++){
        //sum[i][0]값의 최소값 구하기 이전 경로의 최솟값들의 합과 현재 경로의 값의 합을 비교
        if(sum[i-1][0]>=sum[i-1][1]){
            sum[i][0] = a[i][0] + sum[i-1][0];
        }
        else {
            sum[i][0] = a[i][0] + sum[i-1][1];
        }

        //sum[i][1]값의 최소값 구하기
        if(sum[i-1][0]>=sum[i-1][1] && sum[i-1][0]>=sum[i-1][2]){
            sum[i][1] = a[i][1] + sum[i-1][0];
        }
        else if (sum[i-1][1]>=sum[i-1][0] && sum[i-1][1]>=sum[i-1][2]){
            sum[i][1] = a[i][1] + sum[i-1][1];
        }
        else if(sum[i-1][2]>=sum[i-1][0] && sum[i-1][2]>=sum[i-1][1]) {
            sum[i][1] = a[i][1] + sum[i-1][2];
        }
        else {
            printf("something wrong\n");
        }

        //sum[i][2]값의 최소값 구하기
        if(sum[i-1][1]>=sum[i-1][2]){
            sum[i][2] = a[i][2] + sum[i-1][1];
        }
        else {
            sum[i][2] = a[i][2] + sum[i-1][2];
        }
        //printf("%d %d %d\n", sum[i][0], sum[i][1], sum[i][2]);
    }
    int i=size;
    if(sum[i][0]>=sum[i][1] && sum[i][0]>=sum[i][2]){
        anw = sum[i][0];
    }
    else if (sum[i][1]>=sum[i][0] && sum[i][1]>=sum[i][2]){
        anw = sum[i][1];
    }
    else if(sum[i][2]>=sum[i][0] && sum[i][2]>=sum[i][1]) {
        anw = sum[i][2];
    }    
    //printf("final largeScore is %d\n",anw);

    largeScore=anw;
    return largeScore;
}

int main () {
    int size=0;
    scanf("%d",&size);
    for(int i=1; i<=size;i++){
        scanf("%d %d %d",&a[i][0], &a[i][1], &a[i][2]);
    }

    printf("%d %d", findLargeScore(size), findSmallScore(size));
}