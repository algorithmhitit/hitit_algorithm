//암호만들기
//1759
//https://www.acmicpc.net/problem/1759
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
vector<char> alp;//alp을 char 형 배열로 받음
vector<char> str;
set<string> se;
int visit[20];
char vowel[5] = {'a','e','i','o','u'};
int moeum,jaeum;
bool moeumCheck = false;
int pwlen,alpNum;

void back_tracking(int idx, int cnt, string s) {
    // 문자열 길이가 최종 길이와 같다면
    if(cnt == pwlen) {
        // 모음 갯수, 자음 갯수
        int chk1 = 0, chk2 = 0;
        // 알파벳 중복 체크
        int visited[27] = {0, };
 
        for(int i = 0; i < s.length(); i ++) {
            // 모음인 경우
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                chk1 ++;
            }
 
            // 자음인 경우
            else {
                // 중복 자음이 아닌 경우 카운트 증가
                if(!visited[s[i]-'0'-48])
                    chk2 ++;
            }
        }
        // 모음이 하나 이상이고 서로 다른 자음이 2개이상 사용하면 set에 저장
        if(chk1 >= 1 && chk2 >= 2)
            se.insert(s);
        return;
    }
 
    for(int i = idx; i < alpNum; i ++) {
        // 문자를 선택한 경우
        back_tracking(i + 1, cnt + 1, s + alp[i]);
        // 선택하지 않고 지나친 경우
        back_tracking(i + 1, cnt, s);
    }
}

//모음은 최소 1개 자음은 최소 2개라 했으니까 모음 1개만 체크하면 될것 같다.
//입력받은 문자열들은 먼저 배열
//
int main() {
    char tmp;
    scanf("%d %d",&pwlen,&alpNum);

    for(int i=0;i<alpNum;){
        scanf("%c",&tmp);
        if((tmp >= 'a') && (tmp <= 'z')){
            alp.push_back(tmp);
            i++;
        }
    }
    
    sort(alp.begin(),alp.end());

    back_tracking(0, 0, "");

    while(!se.empty()){
        cout << *se.begin() << endl;
        se.erase(*se.begin());
    }

    return 0;
}