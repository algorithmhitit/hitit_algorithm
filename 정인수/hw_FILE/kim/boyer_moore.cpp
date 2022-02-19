#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int jump[1000];
int A1[1000];

void computeJump(char A[],char P[],int n ,int m){
    int tmp[1000];
    for(int i=0;i<=128;i++){
        jump[i] = m;
    }
    for(int i=0;i<=m;i++){
        tmp[i] = m-i;
        if(i==m){
            tmp[i] = m;
        }
    }
    for(int i=0;i<=m;i++){
        jump[(int)P[i]] = min(jump[(int)P[i]],tmp[i]);
    }
    /*for(int i=0;i<=m;i++){
        cout << "tmp[" << i << "]" << tmp[i] << endl;
    }*/
}

void BoyerMooreHorspool(char A[],char P[],int n, int m){
    computeJump(A,P,n,m);
    int i = 1;
    int count = 0;
    int match = 0;
    while(i <= n-m+1){
        int j = m;
        int k = i+m-1;
        while(j>0 && P[j] == A[k]){
            count++;
            j--;
            k--;
        }
        if(j==0){
            match++;
        }
        i = i + jump[(int)A[i+m-1]];
    }
    cout << count << ' ' << match << endl;
}

int main () {
    char A[1000];
    char P[1000];
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
    BoyerMooreHorspool(A,P,n,m);
    //preprocessing(P,m);
    /*for(int i=0;i<=m;i++){
        cout << "pi[" << i << "]" << pi[i] <<endl;
    }*/

    return 0;
}