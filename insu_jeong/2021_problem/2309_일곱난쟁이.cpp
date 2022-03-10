#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;



int main() {
    int a[9]={0,};//난쟁이 키 초기화
    int sum=0;

    for(int i=0;i<9;i++){
        cin>>a[i];
        sum = sum + a[i];
    }

    sort(a,a+9);    
    // cout << "sum = "<< sum << endl;
    // for(int i=0;i<9;i++){
    //     cout << a[i] << endl;
    // }

    int tmp;
    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            tmp = sum - a[i] - a[j];
            if(tmp==100){
                for(int k=0;k<9;k++){
                    if(k != i && k != j)
                        cout << a[k] << endl;
                }
                return 0;
            }
        }
    }

    return 0;
}