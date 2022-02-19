#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int pi[1000];

void preprocessing(char P[], int m){
    for(int i=0;i<=m;i++){
        pi[i] = 0;
    }
    int i = 0;
    int j=1;
    pi[j] = i;
    while(j<=m){
        if(i == 0 || (i>=1 && P[i] == P[j])){
            i++;
            j++;
            pi[j] = i;
        }
        else {
            i = pi[i];
        }
    }
}

void KMP(char A[], char P[], int n, int m){
    preprocessing(P,m);
    int i=1;
    int j=1;
    int count =0;
    bool fail = true;
    while(i<=n){
        count++;
        if(j == 0 || A[i] == P[j]){
            i++;
            j++;
        }
        //일치하지 않을때
        else{
            j=pi[j];
        }
        if(j==m+1) {
            fail = false;
            cout << count << endl;
            j = pi[j];
        }
    }
    if(i==n+1 && fail){
        cout<< "fail"<< endl;
    }
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
    KMP(A,P,n,m);
    //preprocessing(P,m);
    /*for(int i=0;i<=m;i++){
        cout << "pi[" << i << "]" << pi[i] <<endl;
    }*/

    return 0;
}