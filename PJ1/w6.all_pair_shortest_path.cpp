#include <iostream>
#include <vector>

const int INF = 1e9;

int main() {
    int n, m;
    std::cin >> n >> m;
    
    // Initialize the distance matrix with infinity
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
    
    // Set the diagonal elements to 0
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    
    // Read the edges and weights
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        dist[u - 1][v - 1] = w; // Adjust for 0-based indexing
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Print the distance matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                std::cout << -1 << " ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}
