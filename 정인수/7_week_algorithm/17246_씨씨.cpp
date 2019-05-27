/*#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
    int nodeNum, adjNum, testNum;
    int from, to, val;
    int start, end;

    vector< pair<int,int> > adj[201];
    vector<int> dist(201,INT_MAX);
    priority_queue< pair<int,int> > q;
    scanf("%d %d",&nodeNum,&adjNum);

    for(int i=0; i<adjNum;i++){
        scanf("%d %d %d",&from,&to,&val);
        adj[from].push_back(make_pair(to,val));
        adj[to].push_back(make_pair(from,val));
    }

    scanf("%d",&testNum);

    for(int i=0; i<testNum;i++){
        scanf("%d %d", &start, &end);
        for(int j=1;j<=nodeNum;j++){
            dist[i] = INT_MAX;
        }
        dist[start] = 0;
        q.push(make_pair(0,start));
        while(!q.empty()) {
            int here = q.top().second;
            int hereDist = dist[here];
            q.pop();
            for(int j=0;j<adj[here].size();j++){
                int there = adj[here][j].first;
                int thereVal = adj[here][j].second;
                int thereDist = hereDist + thereVal;
                if(dist[there] > thereDist){
                    dist[there] = thereDist;
                    q.push(make_pair(-thereVal,there));
                }
            }
        }
        if(dist[end] == INT_MAX)
            printf("-1\n");
        else
            printf("%d\n",dist[end]);
    }

    return 0;
}*/

#include <stdio.h>
#define INF 1000000

int main (){
    int nodeNum,adjNum;
    int dist[201][201] = {0,};
    scanf("%d",&nodeNum);
    scanf("%d",&adjNum);
    int from, to, val;
    
    for(int i=1;i<=nodeNum;i++){
        for(int j=1;j<=nodeNum;j++){
            if(i != j)
                dist[i][j] = INF;
        }
    }
    
    for(int i=0;i<adjNum;i++){
        scanf("%d %d %d", &from, &to, &val);
        if(dist[from][to] > val){
            dist[from][to] = val;
            dist[to][from] = val;
        }
    }

    for (int m = 1; m <= nodeNum; m++) //가운데 노드
		for (int s = 1; s <= nodeNum; s++) //시작 노드
			for (int e = 1; e <= nodeNum; e++) //마지막 노드
				if (dist[s][e] > dist[s][m] + dist[m][e])
					dist[s][e] = dist[s][m] + dist[m][e]; 

    int testCount = 0;
    int start,end;
    scanf("%d",&testCount);
    for(int i=0;i<testCount;i++){
        scanf("%d %d",&start,&end);
        if(dist[start][end] == INF)
            printf("-1\n");
        else
            printf("%d\n",dist[start][end]);
    }

    return 0;
}