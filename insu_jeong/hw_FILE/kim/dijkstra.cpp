#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#define INF 100000000
using namespace std;

int dijkstra();

int main () {
    int nodeNum, adjNum;
    int from,to,val;
    int startNode,endNode;
    scanf("%d %d",&nodeNum, &adjNum);
    vector<int> dist(nodeNum+1,INF);
    vector< pair<int,int> > adj[nodeNum+1];
    vector<int> prev(nodeNum+1);
    for(int i=0;i<adjNum;i++){
        scanf("%d %d %d",&from,&to,&val);
        adj[from].push_back(make_pair(to,val));
        //adj[to].push_back(make_pair(from,val));//양방향 그래프
    }
    scanf("%d %d",&startNode,&endNode);

    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0,startNode));
    dist[startNode] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int hereDist = dist[here];
        pq.pop();
        for(int i=0;i<adj[here].size();i++){
            int there = adj[here][i].first;
            int thereVal = adj[here][i].second;
            if(dist[there] > hereDist + thereVal){
                dist[there] = hereDist + thereVal;
                prev[there] = here;
                pq.push(make_pair(-thereVal,there));
            }
        }
    }
    for(int i=1;i<=nodeNum;i++){
        printf("%d ", prev[i]);
    }

    if(dist[endNode] == INF)
        printf("Impossible");
    else
        printf("%d",dist[endNode]);

    return 0;
}