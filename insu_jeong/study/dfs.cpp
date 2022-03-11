#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,v; // n : the amount of node, m : the amount of edges, v : Root vector
vector<vector<int>> adj;	//vector-vector를 선언, edge
vector<bool> visited;		//node의 방문 여부에 대한 함수vector<vector<int>> adj;

int s, e; // s : start, e : end

void dfs(int node) {
    visited[node] = true;
    cout << node << endl;

    for(int i=0; i< adj[node].size();i++) {
        int next = adj[node][i];

        if(visited[next] == false) {
            dfs(next);  //recursive function
        }
    }
}

int main () {
    cout << "node, edge, root node : "; 
    cin >>n >> m >> v;

    adj.resize(n+1);

    for(int i=0;i<m; i++) {
        cout << "start node, end node :";
        cin >> s >> e; // enter start num, end num
        // Add edges
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    visited = vector<bool>(n + 1, false);
    for(int i=0; i< adj.size();i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);

    // visited = vector<bool>(n+1, false);
    // cout << endl;

    return 0;
}
