//냉동식품
//14625번
//https://www.acmicpc.net/problem/14625
//전북대 프로그래밍대회 기출문제 연습

#include <stdio.h>
#include <stdlib.h>

int main() {
    int startTime[4];//HH:MM형식
    int endTime[4];//HH:MM형식
    int a[4];
    int findNum=0;
    int count=0;
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&findNum);
    startTime[0] = a[0]/10;
    startTime[1] = a[0]%10;
    startTime[2] = a[1]/10;
    startTime[3] = a[1]%10;
    endTime[0] = a[0]/10;
    endTime[1] = a[0]%10;
    endTime[2] = a[1]/10;
    endTime[3] = a[1]%10;
    
    for(int i=0;i<4;i++){
        if(findNum == startTime[i]){
            count++;
            break;
        }
    }
    while(a[0]!=a[2]||a[1]!=a[3]){
        a[1]++;
        if(a[1] == 60){
            a[0]++;
            a[1] = 0;
        }
        startTime[0] = a[0]/10;
        startTime[1] = a[0]%10;
        startTime[2] = a[1]/10;
        startTime[3] = a[1]%10;
        for(int i=0;i<4;i++){
            if(findNum == startTime[i]){
                count++;
                break;
            }
        }
    }
    printf("%d",count);
}