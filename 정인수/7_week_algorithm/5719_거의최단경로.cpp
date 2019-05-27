#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int dijkstra(vector< pair<int,int> > adj[], int start, int end, int nodeNum,vector<int> &dist){
    priority_queue< pair<int,int> > pq; // 첫번째 원소를 기준으로 ordered됨.
    pq.push(make_pair(0,start));//시작 노드를 pq에 넣어준다.
    dist[start] = 0;//시작 노드의 dist는 자기자신이므로 0으로 만들어 준다.
    while(pq.size() != 0){
        //queue에 들어있는 first와 second의 원소들을 here과 hereDist로 옮겨준다.
        int here = pq.top().second;//현제 노드의 위치
        int hereDist = -pq.top().first;//시작 노드에서 현제 노드까지의 최단거리.
        //printf("here = %d, hereDist = %d, adj[here].size() = %d\n",here,hereDist,adj[here].size());
        //pq에 top 값을 옮겨주었으므로 pop을 해서 비워준다.
        pq.pop();
        //현재 node와 연결되있는 node들의 dist 값을 계산하고 최단 경로일 경우dist를 update및 pq에 넣어준다.
        for(int i=0;i<adj[here].size();i++){
            if(adj[here][i].second != -1){
                int there = adj[here][i].first;                 //현재 node와 인접한 node
                int thereDist = hereDist + adj[here][i].second; //현재 node를 거친 인접한 node의 최단거리 
                //printf("size : %d,there = %d,thereDist = %d\n",adj[here].size() ,there,thereDist);
                //기존의 경로의 최단거리가 새로 찾은 최단거리보다 작다면 dist를 update 해준다.
                if(dist[there] > thereDist){
                    dist[there] = thereDist;
                    //printf("pqpush : dist[%d](there)  = %d\n",there,dist[there]);
                    pq.push(make_pair(-dist[there],there));
                }
            }
        }
        
    }
    int ans = dist[end];
    if(dist[end] == INT_MAX){
        ans = -1;
    }
    return ans;
}

int similar_Shortpass(vector< pair<int,int> > adj[],vector< pair<int,int> > prev[]
                        , int start, int end, int nodeNum) {
    vector<int> dist(nodeNum,INT_MAX);//node의 크기만큼 dist 배열을 INT_MAX로 초기화 해준다.
    queue<int> q;
    dijkstra(adj,start,end,nodeNum,dist);// 다익스트라로 최당경로를 구한다.
    //최단 경로를 제거해주는 작업
    q.push(end);
    while(q.size() != 0){
        int here = q.front();
        //printf("q.front() = %d\n",here);
        q.pop();
        for(int i=0;i<prev[here].size();i++){
            int p = prev[here][i].first;//이전 node
            int v = prev[here][i].second;//가중치
            //printf("dist[%d](p) = %d,dist[%d](here) = %d, v = %d\n",p,dist[p],here,dist[here],v);
            
            if(dist[p] == (dist[here] - v)){
                
                //////////문제부분////////////
                //adj[p][i].second = -1;
                for(int j=0;j<adj[p].size();j++){
                    if(adj[p][j].first == here){
                        if(adj[p][j].second != -1){
                            adj[p][j].second = -1;
                            dist[p] = dist[here]-v;
                            //if(p != start )
                            q.push(p);
                            break;
                        }
                        else{
                            break;
                        }
                    }
                }
                /////////////////////
                //printf("adj[%d][%d].first = %d, .second = %d\n",p,i,adj[p][i].first,adj[p][i].second);
                //dist[p] = dist[here]-v;
                //if(p != start )
                //q.push(p);
            }
        }
    }
    //dist 초기화
    for(int i=0;i<nodeNum;i++){
        dist[i] = INT_MAX;
    }
    int ans = dijkstra(adj,start,end,nodeNum,dist);//거의 최단 경로를 구해준다.
    return ans;
}

int main () {
    //변수 선언부
    int nodeNum,adjNum;//node의 개수, 간선의 개수
    int start, end; // 시작 노드, 목적지 노드
    int ans;//거의 최단경로의 값을 저장
    int from,to,val; // from: 현제 노드, to : 다음 노드 ,val : 가중치
    //adj의 수는 최대 10000개까지,index = from, first = to, second = val
    vector< pair<int,int> >  adj[10000];
    //prev를 저장하는 배열
    vector< pair<int,int> > prev[10000];
    // //거의 최단경로 구하기
    while(true) {
        scanf("%d %d", &nodeNum, &adjNum);
        //종료조건 nodeeNum과 adjNum이 0이면 끝난다.
        if((nodeNum == 0) && (adjNum == 0))
            return 0;
        //시작노드와 목적지 노드를 입력받는다. 
        scanf("%d %d", &start, &end);
        //adj[]에 도로정보 입력
        for(int i=0;i<adjNum;i++){
            scanf("%d %d %d", &from, &to, &val);
            adj[from].push_back(make_pair(to,val));
            prev[to].push_back(make_pair(from,val));//prev[노드이름]에는 이 노드 이전의 노드의 개수가 저장
        }
        for(int i=0;i<nodeNum;i++){
            for(int j=0;j<adj[i].size();j++){
                //printf("from = %d, to = %d, val = %d\n", i, adj[i][j].first,adj[i][j].second);
            }
        }

        //거의 최단경로 구하기 호출
        ans = similar_Shortpass(adj,prev,start,end,nodeNum);
        //ans = dijkstra(adj,start,end,nodeNum,dist);
        printf("%d\n",ans);

        //vector 초기화
        for(int i=0;i<nodeNum;i++)
            adj[i].clear();
    }
    return 0;
}