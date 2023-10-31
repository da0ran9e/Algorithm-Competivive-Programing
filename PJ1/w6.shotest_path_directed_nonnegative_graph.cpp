#include <iostream>
#include <vector>
#include <queue>
#include <climits>

const int INF = INT_MAX;

struct Edge {
    int to;
    int weight;
};

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<Edge>> graph(n);
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w}); // Adjust for 0-based indexing
    }
    
    int s, t;
    std::cin >> s >> t;
    s--; // Adjust for 0-based indexing
    t--; // Adjust for 0-based indexing
    
    std::vector<int> dist(n, INF);
    dist[s] = 0;
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
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
        std::cout << dist[t] << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}
