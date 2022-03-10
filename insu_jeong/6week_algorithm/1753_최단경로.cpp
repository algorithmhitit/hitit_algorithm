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

vector<int> dijkstra(int src, int V, int E) {
    vector<int> dist(V, INT_MAX);//dist를 v개 생성하고 INT_MAX로 전부 초기화한다.
    dist[src] = 0;

    //queue
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0,src));

    //priority queue가 빌때까지 돌아간다.
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;

        pq.pop();

        if(dist[here] < cost)
            continue;
        
        for(int i=0;i< adj[here].size();i++){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if(dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist,there));
            }
        }
    }
    return dist;
}

int main() {
    int V,E,start;
    scanf("%d %d",&V, &E);
    scanf("%d", &start);
    V++;
    for(int i=0;i<E;i++){
        int from,to,val;
        scanf("%d %d %d",&from,&to,&val);
        //push_back 값 복사를 통해 요소를 추가,객체의 복사가 아닌 이동을 통해 요소를 추가
        //오버헤드를 줄였다.
        adj[from].push_back(make_pair(to,val));//from에 간선들의 배열을 추가로 만들수 있다.
    }

    vector<int> ans = dijkstra(start,V,E);

    for(int i=1;i<V;i++)
        ans[i] == INT_MAX ? printf("INF\n") : printf("%d\n",ans[i]);

    return 0;
}