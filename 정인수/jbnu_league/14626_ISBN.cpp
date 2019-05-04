//ISBN
//14626번
//https://www.acmicpc.net/problem/14626
//푸는중
#include <stdio.h>

int main() {
    char a[13];
    int b[13];
    int value=0;
    int ans=0;
    int ast;//ast는 *이 어느 위치 index에 있는지 알려줌
    for (int i=0;i<13;i++){
        scanf("%c",&a[i]);
    }
    for(int i=0;i<13;i++){
        b[i] = a[i] - 48;//* = -6
        //printf("%d ",b[i]);
        if(b[i] == -6){
            ast = i;
            //printf("ast = %d ",ast);
        }
    }
    if(ast !=12){
        for(int i=0;i<12;i++){
            if(i != ast){
                if(i%2 == 0)
                    value = value + b[i];
                else
                    value = value + 3*b[i];            
            }
        }
        if(ast%2 == 0){
            ans = (10 - (b[12]+value)%10)%10;
        }
        else {
            ans = 10-(b[12]+value)%10;
            if(ans == 1)
                ans=7;
            else if(ans == 2)
                ans=4;
            else if(ans == 3)
                ans=1;
            else if(ans == 4)
                ans=8;
            else if(ans == 5)
                ans=5;
            else if(ans == 6)
                ans=2;
            else if(ans == 7)
                ans=9;
            else if(ans == 8)
                ans=6;
            else if(ans == 9)
                ans=3;
            else if(ans == 10)
                ans=0;
        }
    }
    else {
        for(int i=0;i<12;i++){
            if(i%2 == 0)
                value = value + b[i];
            else
                value = value + 3*b[i];            
        }
        ans = (10-(value)%10)%10;
    }

    printf("%d",ans);

    return 0;
}