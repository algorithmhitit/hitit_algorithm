//slr파싱표 만들기
//문법 G = (Vn,Vt,P,S)
//증가문법 G'에 대한 SLR 파싱표
//방법1. G'을 위한 LR(0) 항목 집합의 정규 항목 집합 C0 = {i0,i1,....., in}을 구성한다.
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const char delimiter = ' ';

typedef struct grammar {
    string nonTerminal;
    vector<string> token;
} GRAMMAR;

/**************************/
//  first 계산    //
/**************************/
int ringSum();              //fisrt 함수를 구현하기 위한 ring sum 연산자

int FIRST(int x){
    //return ringSum(FIRST[A[1]],FISRT[A[2]]]);
}

/**************************/
//  LR(0)만들기    //
/**************************/




/**************************/
//  LR 구문분석 알고리즘    //
/**************************/
/*#include <queue>

int ip = string()
if(ip = w$)
*/


int main(){    
    int grammar_size = 0;       //nonterminal문법의 개수
    printf("input grammar size : ");
    scanf("%d", grammar_size);
    vector<string> stream;     //2차원 백터 선언,여기에 각 문법을 저장
    vector<GRAMMAR> G(6);

    string token;
    for(int i=0;i<grammar_size;i++){
        //getline(stream,token,delimiter);
        G[i].nonTerminal = token;
        while(getline(stream,token,delimiter)){
            G[i].token.push_back(token);
        }
    }

    return 0;
}
