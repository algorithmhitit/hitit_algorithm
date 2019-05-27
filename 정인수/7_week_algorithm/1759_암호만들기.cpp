//암호만들기
//1759
//https://www.acmicpc.net/problem/1759
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
char vowel[5] = {a,e,i,o,u};

void find_password(vector<char> alp, int alpNum, int pwLen,int count, int index, bool valid) {
    for(int i=index;i<alpNum;i++){
        for(int j=0;j<5;j++){
            alp[i] == vowel[j];
            valid = true;
        }
        printf("%c",alp[i]);
        count--;//pwlen과 같다
        if(pwLen != 0){
            find_password(alp,alpNum,pwLen,count,i,valid)
        }
        else{
            if(valid) {
                for(int j=0;j<)
                alp[possible_pw][i]
            }
        }
    }
}

//모음은 최소 1개 자음은 최소 2개라 했으니까 모음 1개만 체크하면 될것 같다.
//입력받은 문자열들은 먼저 배열
//
int main() {
    int pwlen,alpNum;
    char tmp;
    scanf("%d %d",&pwlen,&alpNum);
    vector<char> alp;//alp을 char 형 배열로 받음
    for(int i=0;i<alpNum;){
        scanf("%c",&tmp);
        if((tmp >= 'a') && (tmp <= 'z')){
            alp.push_back(tmp);
            i++;
        }
    }
    
    sort(alp.begin(),alp.end());

    find_password(alp,alpNum,pwlen,0,false);

    for(int i=0;i<alpNum;i++){
        printf("%c ",alp[i]);
    }

    return 0;
}