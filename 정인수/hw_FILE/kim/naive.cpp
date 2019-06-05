#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int count = 0;

bool isMatching(string A, string P,int index, int m){
    int k=0;
    for(int i=index;i<index+m;i++){
        count++;
        if(A[i] != P[k++]){
            return false;
        }
    }
    return true;
}

void naiveMatching(string A,string P, int n, int m){
    int matching = 0;
    for(int i=0;i<n-m+1;i++){
        if(isMatching(A,P,i,m)){
            matching++;
        }
    }
    cout << count << " " << matching << endl;
}

int main () {
    int n=0;//length of A
    int m=0;//length of P
    string A;//string
    string P;//pattern string
    
    cin >> A;
    cin >> P;
    n = A.size();
    m = P.size();
    //cout << A << n << endl;
    //cout << P << m << endl;
    naiveMatching(A,P,n,m);
    return 0;
}