//너의 이름은 몇점이니?
//15813번
//https://www.acmicpc.net/problem/15813

#include <stdio.h>

int main(){
    char a[101];
    int num =0;
    int ans =0;
    scanf("%d",&num);
    for(int i=0;i<=num;i++){
        scanf("%c",&a[i]);
    }
    for(int i=1;i<=num;i++){
        ans = ans + a[i]-64;
    }
    printf("%d",ans);
    return 0;
}