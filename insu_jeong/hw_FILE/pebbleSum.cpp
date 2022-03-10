#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[3][100];
int dp[4][100];

int pebbleSum(int column);

int main() {
    int column = 0;
    scanf("%d",&column);
    for(int i=0;i<3;i++){
        for(int j=0;j<column;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("%d",pebbleSum(column));

    return 0;
}

int pebbleSum(int column){
    for(int i=0;i<column;i++){
        if(i==0){
            dp[0][i] = arr[0][i];
            dp[1][i] = arr[1][i];
            dp[2][i] = arr[2][i];
            dp[3][i] = arr[0][i] + arr[2][i];
        }
        else {
            dp[0][i] = max(dp[1][i-1],dp[2][i-1]) + arr[0][i];
            dp[1][i] = max(max(dp[0][i-1],dp[2][i-1]),dp[3][i-1]) + arr[1][i];
            dp[2][i] = max(dp[0][i-1],dp[1][i-1]) + arr[2][i];
            dp[3][i] = dp[1][i-1] + arr[0][i] + arr[2][i];
        }
    }
    int lastIndex = column-1;
    return max(max(dp[0][lastIndex],dp[1][lastIndex]),max(dp[2][lastIndex],dp[3][lastIndex]));
}