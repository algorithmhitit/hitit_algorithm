#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int preprocessing(char P[], int m){

}

void KMP(char A[], char P[], int n, int m){
    preprocessing(P,m);
    int i=1;
    int j=1;
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
    }
}

int main () {
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
    KMP(A,P,n,m);
    //preprocessing(P,m);
    for(int i=0;i<=m;i++){
        cout << "pi[" << i << "]" << pi[i] <<endl;
    }

    return 0;
}