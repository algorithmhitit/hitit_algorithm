//풍선공장
//15810번
//https://www.acmicpc.net/problem/15810
#include <stdio.h>
#include <algorithm>

int a[1000000];

bool cmp(int a, int b) {
	return a<b;
}

int main() {
    int staff=0,ballon=0;
    int ans=0;
    scanf("%d %d",&staff,&ballon);
    for(int i=0;i<staff;i++){
       scanf("%d",&a[i]); 
    }

    std::stable_sort(a,a+staff,cmp);

    int btime=0;

    while(true){
        ans = 0;
        btime = btime + a[staff-1];
        for(int j=0;j<staff;j++){
            ans =  ans + btime/a[j];
        }
        if(ans > ballon){
            for(int i=btime-a[staff-1];i<=btime;i++){
                ans = 0;
                for(int j=0;j<staff;j++){
                    ans = ans + i/a[j];
                }
                if(ans >= ballon){
                    ans = i;
                    printf("%d",ans);
                    return 0;
                }
            }
        }
        else if(ans == ballon){
            ans = btime;
            printf("%d",ans);
            return 0;
        }
    }

    printf("%d",ans);
    return 0;
}