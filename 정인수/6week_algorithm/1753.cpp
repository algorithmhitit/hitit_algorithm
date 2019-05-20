//최단경로
//1753번
//https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstdio>

using namespace std;

vector< pair<int,int> > abj[20001];

vector<int> dijkstra(int start,int V, int E){
    
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

    for(int i=0;i<V;i++){
        ans[i] == INT_MAX ? printf("INF\n") :printf("%d\n",ans[i]);
    }

    return 0;
}