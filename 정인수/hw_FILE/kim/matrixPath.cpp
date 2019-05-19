#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][100]={0,};
int dp[100][100]={0,};

int findRoot(int row, int column){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(i==0 && j==0){
                dp[i][j] = arr[i][j];
            }
            else if(i==0){
                dp[i][j] = dp[i][j-1] + arr[i][j];
            }
            else if(j==0){
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else {
                dp[i][j]=arr[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[row-1][column-1]; 
}

int main () {
    int row,column;
    scanf("%d %d",&row,&column);
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("%d",findRoot(row,column));

    return 0;
}