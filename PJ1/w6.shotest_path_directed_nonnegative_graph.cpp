#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to;
    int weight;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<Edge>> graph(n);
    
    for (int i=0; i<m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
    }
    
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    
    vector<int> dist(n, INF);
    dist[s] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    if (dist[t] != INF) {
        cout << dist[t] << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
