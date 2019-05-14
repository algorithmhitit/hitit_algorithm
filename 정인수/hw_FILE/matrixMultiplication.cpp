#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[100][2];
int dp[100][100]={0,};

int matrixM(int);

int main () {
    int ans=0;
    int size=0;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    ans = matrixM(size);
    printf("%d",ans);
    
    return 0;
}

int matrixM(int size){
    int mindp=0;
    int cij=0;
    for(int i=0;i<size;i++){
        dp[i][i] = 0;
    }
    int j=0;
    for(int r=0;r<size;r++){
        for(int i=0;i<size-r;i++){
            mindp = 1000000000;
            j = i+r;
            for(int k=i;k<=j-1;k++){
                cij = dp[i][k]+dp[k+1][j]+arr[i][0]*arr[k][1]*arr[j][1];
                mindp = min(mindp,cij);
                if(mindp == cij){
                    dp[i][j] = mindp;
                }
            }
        }
    }

    return dp[0][size-1];
}