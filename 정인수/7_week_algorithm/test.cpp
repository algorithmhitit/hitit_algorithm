#include <iostream>
#include <cstdio>
 
#define INF 987654321
#define min(a,b)(a < b ? a : b)
using namespace std;
 
int adj[101][101];
int dist[101][101];
 
int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
 
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            i == j ? adj[i][j] = 0 : adj[i][j] = INF;
 
    for (int i = 0; i < E; i++)
    {
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);
        adj[from][to] = min(adj[from][to], val);
    }
 
    for (int k = 1; k <= V; k++)
        for (int x = 1; x <= V; x++)
            for(int y = 1; y <= V; y++)
                if (adj[x][y] > adj[x][k] + adj[k][y])
                    adj[x][y] = adj[x][k] + adj[k][y];
 
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
            printf("%d ", adj[i][j] == INF ? 0 : adj[i][j]);
        printf("\n");
    }
 
    return 0;
}
