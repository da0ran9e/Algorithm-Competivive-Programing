#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
  
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i=0; i<n; ++i) {
        dist[i][i] = 0;
    }
    
    for (int i=0; i<m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u - 1][v - 1] = w; 
    }
    
    // Floyd-Warshall
    for (int k=0; k<n; ++k) {
        for (int i=0;i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Print
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (dist[i][j] == INF) {
                cout << -1 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
