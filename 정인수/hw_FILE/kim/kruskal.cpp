/*#include <stdio.h>
#include <vector>
using namespace std;
int parent[1000];
int adj[1000];

int main() {
    int nodeNum,adjNum;
    int from,to,val;
    scanf("%d",&nodeNum,&adjNum);
    vector< pair<int,int> > adj[nodeNum+1];
    for(int i=0;i<adjNum;i++){
        scanf("%d %d %d",&from,&to,&val);
        adj[from].push(make_pair(to,val));
    }

    for(int i=0;i<)
}*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_VER     100000
#define MAX_EDGE    100000

typedef struct edge{
    int s,d;
    int w;
}EDGE;

struct vertices{
    int p;
    int rank;
}vt[MAX_VER];

EDGE e[MAX_EDGE];

bool compare(EDGE a,EDGE b){
    return a.w < b.w;
}

void make_set( int v)
{
    vt[v].p     = v;
    vt[v].rank  = 0;
}

int find_set( int v)
{
    if( vt[v].p != v){
        vt[v].p = find_set( vt[v].p);
    }
    return vt[v].p;
}

void connect( int v, int u)
{
    v   = find_set( v);
    u   = find_set( u);

    if( vt[v].rank > vt[u].rank){
        vt[u].p = v;
    }
    else{
        vt[v].p = u;
        if( vt[v].rank == vt[u].rank){
            vt[u].rank = vt[u].rank + 1;
        }
    }
}

void mst_kruskal( int nodeNum, int adjNum)
{
    int i;
    int total   = 0;
    for( i = 0 ; i < nodeNum ; i ++){
        make_set(i);
    }
    for( i = 0  ; i < adjNum ; i ++){
        if( find_set( e[i].s) != find_set( e[i].d)){
            connect( e[i].s, e[i].d);
            total = total + e[i].w;
            printf("%d ",e[i].w);
        }
    }
    printf("%d ",total);
}

int main()
{
    int nodeNum,adjNum;
    int from,to,val;
    scanf("%d %d",&nodeNum,&adjNum);
    for(int i=0;i<adjNum;i++){
        scanf("%d %d %d",&from,&to,&val);
        e[i].s = from;
        e[i].d = to;
        e[i].w = val;
    }

    sort(e,e+adjNum,compare);
    mst_kruskal(nodeNum,adjNum);

    return 0;
}
