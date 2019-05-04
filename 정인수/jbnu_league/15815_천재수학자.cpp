//천재 수학자 성필
//15815
//https://www.acmicpc.net/problem/15815
#include<stdio.h>

int cal(int a, int b, char c){
    if(c=='*'){
        a=a*b;
    }
    else if(c == '-'){
        a=a-b;
    }
    else if(c == '+'){
        a=a+b;
    }
    else if(c == '/'){
        a=a/b;
    }
    return a;
}

int main(){
    char a[200]={0,};
    int b[100]={0,};//숫자
    int bcount=0;
    char c[100];//연산자
    int ccount=0;
    int tmp=0;
    char *str = a;
    scanf("%s",str);
    for(int i=0;i<200;i++){
        if(a[i] == NULL){
            break;
        }
        if(a[i]>=48 &&a[i]<=57){
            b[bcount] = a[i]-48;
            //printf("b[%d] = %d\n",bcount,b[bcount]);
            bcount++;
        }
        else{
            c[ccount] = a[i];
            //printf("c[%d] = %c\n",ccount,c[ccount]);
            ccount++;
        }
    }
    for(int i=bcount-1;i>=1;i--){
        b[i-1] = cal(b[i-1],b[i],c[tmp]);
        //printf("b[%d] = %d\n",i-1,b[i-1]);
        tmp++;
    }
    printf("%d",b[0]);
    return 0;
}