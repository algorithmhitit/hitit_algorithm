//계단오르기
//2579번
//https://www.acmicpc.net/problem/2579

#include <stdio.h>

int main() {
    int a[300] = {0,};//계단의 점수의 배열
    int b[300] = {0,};//전의 계단에서 2칸을 뛴 경우의 최대값
    int c[300] = {0,};//ㅓ연속된 2개의 계단을 올랐을때의 최대값
    int n=0;//계단의 개수
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int i=0;
    int ans=0;//계단에 저장된 값들의 합
    while(i<n){
        //계단을 한칸 뛰었을 경우
        if(i==0){
            b[i]=a[i];
            c[i]=a[i];
        }
        else if(i==1){
            b[i] = a[i];
            c[i] = c[i-1] + a[i];
        }
        else {
            //한칸 떨어진 계단
            if(b[i-2]>c[i-2]){
                b[i] = b[i-2] + a[i]; // 한칸 떨어진 수
            }
            else{
                b[i] = c[i-2] + a[i];
            }
            //연속된 계단
            c[i] = b[i-1] +a[i]; // 연속된 두개의 수
        }
        i++;
    }
    //가장 큰 수를 ans에 넣어준다.
    if(c[i-1]>=b[i-1]){
        ans = c[i-1];
    }
    else {
        ans =b[i-1];
    }
    
    printf("%d",ans);

    return 0;
}