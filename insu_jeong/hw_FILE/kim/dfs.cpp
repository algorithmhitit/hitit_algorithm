#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visit(1000,false);
vector<int> adj[1000];
void dfs(int currentNode){
    for(int i=0;i<adj[currentNode].size();i++){
        int there = adj[currentNode][i];
        if(!visit[there]){
            printf("%d ",there);
            visit[there] = true;
            dfs(there);
        }
    }
}

int main () {
    int nodeNum,ajdNum;
    int startNode;
    int from,to;
    scanf("%d %d",&nodeNum,&ajdNum);
    
    for(int i=0;i<ajdNum;i++){
        scanf("%d %d",&from,&to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    scanf("%d",&startNode);

    for(int i=1;i<=nodeNum;i++){
        sort(adj[i].begin(),adj[i].end());
    }

    visit[startNode] = true;
    printf("%d ",startNode);
    dfs(startNode);
    
    return 0;
}