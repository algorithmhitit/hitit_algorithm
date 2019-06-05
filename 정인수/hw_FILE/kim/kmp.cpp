#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int pi[1000];

void preprocessing(char P[], int m) {
    for(int i=0;i<=m;i++){
        pi[i] = 0;
    }
    int j=1;
    for(int i=2;i<=m;i++){
        while(j>1 && P[i] != P[j]){
            j = pi[j-1];//불일치가 일어날 경우
        }
        if(P[i] == P[j]){
            pi[i] = j++;//prefix가 같은 가중치 만큼 pi를 정해준다.    
        }
    }
}

void KMP(char A[], char P[],int n,int m){
    int count = 0;
    preprocessing(P,m);
    int j = 1;
    int i = 1;
    while(i<=n){
        count++;
        //문자열이 같을때
        if(j==0||A[i] == P[j]){
            cout << "i = " << i << ", j = "<< j<< endl;
            i++;
            j++;
        }
        /*else if(j==0){
            i++;
        }*/
        //문자열이 같지 않을때
        else{
            cout << "else" <<endl;
            j = pi[j];
        }

        if(j==m){
            cout << i-j << endl;
            cout << count << endl;
            j = pi[j];
        }

    }
}

int main () {
    //string A;//string A
    //string P;//patter P
    //cin >> A;
    //cin >> P;
    //int n = A.size();//n은 A의 크기
    //int m = P.size();//m은 P의 크기
    char A[200];
    char P[200];
    int n=0;
    int m=0;
    while(A[n] != '\n'){
        n++;
        scanf("%c",&A[n]);
    }
    n=n-1;
    while(P[m] != '\n'){
        m++;
        scanf("%c",&P[m]);
    }
    m=m-1;
    for(int i=1;i<=n;i++){
        printf("%c",A[i]);
    }
    printf("\n");
    for(int i=1;i<=m;i++){
        printf("%c",P[i]);
    }
    printf("\n");

    //printf("%s\n%s",A,P);
    printf("n = %d, m = %d",n,m);
    KMP(A,P,n,m);
    //preprocessing(P,m);
    for(int i=0;i<=m;i++){
        cout << "pi[" << i << "]" << pi[i] <<endl;
    }

    return 0;
}