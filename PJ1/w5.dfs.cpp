#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;
vector<int> adj[MAX_N];
bool visited[MAX_N];

void dfs(int u) {
    cout << u << " ";
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }A
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
    dfs(1);

    return 0;
}