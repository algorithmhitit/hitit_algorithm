#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n=0;
    int t[16][2],p[16];
    int total[16] = {0,};
    
    scanf("%d",n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",t[i][0],p[i]);
        t[i][1] = t[i][0] + i - 1;
    }

    for(int i=1;i<=n;i++){
        total[i] = total+p[i];
    }

    return 0;
}