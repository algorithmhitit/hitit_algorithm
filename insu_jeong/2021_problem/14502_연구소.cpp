#include <stdio.h>
#include <iostream>
#define INF 100;

using namespace std;


int main() {
    int a[8][8];
    int tmp[8][8];
    int row=0,col=0;
    bool virus_spread = true;
    bool not_same = false;

    cin >> row >> col;
    // cout << "row = "<<row << ", col = "<< col;
    for(int i = 0; i < row;i++){
        for(int j=0;j<col;j++){
            cin >> a[i][j];
        }
    }

    //virus spread
    //if virus meet wall then stuck
    while(virus_spread){
        for(int i = 0; i < row;i++){
            for(int j=0;j<col;j++){
                tmp[i][j] = a[i][j];
            }
        }
        cout << "1";
        for(int i = 0; i < row;i++){
            for(int j=0;j<col;j++){
               if(a[i][j] == 2){
                    if(i != row-1 && a[i+1][j] != 1)
                        a[i+1][j] = 2;
                    if(j != col-1 && a[i][j+1] != 1)
                        a[i][j+1] = 2;
                    if(i != 0 && a[i-1][j] != 1)
                        a[i-1][j] = 2;
                    if(j != 0 && a[i][j-1] != 1)
                        a[i][j-1] = 2;
                } 
            }
        }
        cout <<"2";
        not_same = false;
        for(int i = 0; i < row;i++){
            for(int j=0;j<col;j++){
                if(tmp[i][j] != a[i][j]){
                    cout << "i = "<< i <<",j = " << j <<",a =" << a[i][j] << ",tmp = "<< tmp[i][j] << endl;
                    not_same = true;
                    break;
                }
                else{
                    //cout << "i = "<< i <<",j = " << j << ",a =" << a[i][j] << ",tmp = "<< tmp[i][j] << endl;
                }
            }
        }
        cout<<"3";
        if(not_same = true){
            continue;
        }
        else{
            virus_spread = false;
        }
        cout <<"4";
    }

    for(int i = 0; i < row;i++){
        for(int j=0;j<col;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int min = INF;
    int result;
    if(min > result)
        min = result;
    return 0;
}