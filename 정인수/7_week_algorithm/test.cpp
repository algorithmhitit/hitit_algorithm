#include <iostream>
#include <algorithm>
#define MAX_SIZE 20
using namespace std;
 
char candidate[MAX_SIZE];
char ret[MAX_SIZE];
int visit[MAX_SIZE];
int moeum,jaeum;
 
void dfs(int start,int L , int C,int d)
{
    
    if(d == L) // 깊이가 정해진 갯수에 도달했을때
    {
        if(moeum == 0 || jaeum < 2)return; //모음이 1개도 없거나 , 자음이 2개가 안될경우 출력 불가능하게 리턴
        
        for(int i = 0 ; i < L ; i++)
        {
            cout << ret[i];
        }
        cout <<'\n';
        return;
    }
    
    for(int i = start; i < C ; i++) //시작지점부터 후보군의 갯수만큼 탐색
    {
        if(visit[i]) continue; //방문했을경우 컨티뉴
        
        ret[d] = candidate[i]; // 결과가 될 현재 깊이 위치에 후보군의 문자를 입력.
        if(ret[d]== 'a' || ret[d]== 'e' ||ret[d]== 'i' ||ret[d]== 'o' ||ret[d]== 'u') moeum ++; //모음과 자음의 갯수를 카운팅
        else jaeum ++;
        
        visit[i] = 1;
        dfs(i+1,L,C,d+1);
        visit[i] = 0;
        if(ret[d]== 'a' || ret[d]== 'e' ||ret[d]== 'i' ||ret[d]== 'o' ||ret[d]== 'u') moeum --; // 다시 빼주기
        else jaeum --;
        
    }
}
int main() {
    int L,C;
    cin >> L >> C;
    
    for(int i = 0 ; i < C ; i++)
    {
        cin >> candidate[i];
    }
    
    sort(candidate, candidate+C); // 정렬 , 오름차순으로 출력해주기 위함.
    
    dfs(0,L,C,0); // 재귀 진입
    return 0;
}