#include <stdio.h>
#include <algorithm>
using namespace std;

char arr1[1000000] = {0,};
char arr2[1000000] = {0,};    
int LCS[1000][1000] = {0,};

int lcs(int m,int n){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr1[i-1] == arr2[j-1]){
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else{
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
    return LCS[m][n];
}

int main() {
    int arr1Size=0,arr2Size=0;
    scanf("%s\n%s",arr1,arr2);
    for(int i=0;i<100;i++){
        if(arr1[i] != 0){
            arr1Size++;
        }
        if(arr2[i] != 0){
            arr2Size++;
        }
    }
    //printf("%s sizeof:%d %s sizeof:%d",arr1,arr1Size,arr2,arr2Size);

    int ans=0;
    
    ans = lcs(arr1Size,arr2Size);

    printf("%d",ans);

    return 0;
}