#include <bits/stdc++.h>
using namespace std

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);  // Adjacency list for the graph
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> visited(n + 1, 0);
    
    queue<int> q;
    vector<int> result;
    
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            q.push(i);
            visited[i] = 1;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                result.push_back(node);
                
                sort(adj[node].begin(), adj[node].end());  // Lexicographic order
                
                for (int neighbor : adj[node]) {
                    if (visited[neighbor] == 0) {
                        q.push(neighbor);
                        visited[neighbor] = 1;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    
    cout << endl;
    
    return 0;
}