#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main () {
    int nodeNum,ajdNum;
    int startNode;
    int from,to;
    scanf("%d %d",&nodeNum,&ajdNum);
    vector<bool> visit(nodeNum+1,false);
    vector<int> adj[nodeNum+1];
    for(int i=0;i<ajdNum;i++){
        scanf("%d %d",&from,&to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    scanf("%d",&startNode);

    queue<int> q;
    q.push(startNode);
    while(!q.empty()){
        printf("%d ",q.front());
        int here = q.front();
        q.pop();
        for(int i=0;i<adj[here].size();i++){
            int there = adj[here][i];
            if(!visit[there])
                visit[there] = true;
                q.push(there);
        }
    }

    return 0;
}