//최단경로
//1753번
//https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstdio>

using namespace std;

vector< pair<int,int> > adj[20001];

vector<int> dijkstra(int start,int V, int E){
    priority_queue< pair<int, int> > pq;

    //각 정점을 최대치로 초기화 하여 준다.
    //start로부터 각 정점까지의 최단거리를 저장하는 배열(vector)이다.
    vector<int> dist(V,INT_MAX);
    dist[start] = 0;
    
    //프라이어리티 큐에 처음 노드를 넣어준다.
    pq.push(make_pair(0,start));

    int here = start;

    while(!pq.empty()){
        //priority queue에서 top에 있는 값을 추출해낸다.
        int cost = -pq.top().first;     //cost는 가장 작은 값이 top이 있어야하기 때문에 -로 저장해두어서 -를 붙여 양수로 바꿔줌
        int here = pq.top().second;    //there은 pq에 간선이 가르키는 정점이다.

        //추출이 끝난 요소를 pop해줘서 queue에서 제외하여 준다.
        pq.pop();

        for(int i=0;i<adj[here].size();i++){

            int nextdist = cost + adj[here][i].second;
            int there = adj[here][i].first;

            if(dist[there] > nextdist){
                dist[there] = nextdist;
                pq.push(make_pair(-dist[there],there));
            }
        }

    }

    return dist;
}

int main () {
    int V,E,start;
    scanf("%d %d",&V, &E);
    scanf("%d",&start);
    V++;
    for(int i=0;i<E;i++){
        int from,to,val;
        scanf("%d %d %d",&from,&to,&val);
        
        adj[from].push_back(make_pair(to,val));
    }

    vector<int> ans = dijkstra(start,V,E);

    for(int i=1;i<V;i++){
        ans[i] == INT_MAX ? printf("INF\n") :printf("%d\n",ans[i]);
    }

    return 0;
}