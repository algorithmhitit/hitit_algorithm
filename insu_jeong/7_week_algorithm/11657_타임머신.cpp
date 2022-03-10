#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#define INF 100000000
using namespace std;

int main() {
    int nodeNum,edgeNum;//노드의 개수, 간선의 개수
    int from,to,val;//from : 출발지, to: 목적지, val : 가중치
    bool cycle = false;
    scanf("%d %d", &nodeNum, &edgeNum);
    vector< pair<int,int> >  edge[501];
    
    //간선의 개수만큼 edge의 값을 채워 준다.
    for(int i=0;i<edgeNum;i++){
        scanf("%d %d %d", &from, &to, & val);
        edge[from].push_back(make_pair(to,val));
    }
    vector<int> dist(nodeNum+1,INF);
    //벨만 포드 알고리즘
    dist[1] = 0;    //처음 시작 노드의 거리는 0
    for(int i=1;i<=nodeNum;i++) {
        for(int j=1;j<=nodeNum;j++){
            for(int k=0;k<edge[j].size();k++){
                int there = edge[j][k].first;
                int thereDist = dist[j] + edge[j][k].second;
                if(dist[j] == INF) continue;
                if(dist[there] > thereDist){
                    dist[there] = thereDist;
                    if(i == nodeNum){
                        cycle =true;
                    }
                }
            }
        }
    }

    //출력
    if(cycle){
        printf("-1\n");
    }
    else{
        for(int i=2;i<=nodeNum;i++){
            if(dist[i] == INF)
                printf("-1\n");
            else
                printf("%d\n",dist[i]);
        }
    }

    return 0;
}