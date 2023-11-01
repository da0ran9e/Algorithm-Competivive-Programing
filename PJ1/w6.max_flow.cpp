#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, capacity, flow;
};

vector<vector<Edge>> graph;
vector<int> parent;

int maxFlow(int source, int sink) {
    int flow = 0;
    while (true) {
        fill(parent.begin(), parent.end(), -1);
        queue<pair<int, int>> q;
        q.push({source, INF});

        while (!q.empty()) {
            int cur = q.front().first;
            int capacity = q.front().second;
            q.pop();

            for (Edge& edge : graph[cur]) {
                int next = edge.to;
                if (parent[next] == -1 && edge.capacity - edge.flow > 0) {
                    int new_capacity = min(capacity, edge.capacity - edge.flow);
                    parent[next] = cur;
                    if (next == sink) {
                        flow += new_capacity;
                        int v = next;
                        while (v != source) {
                            int u = parent[v];
                            for (Edge& e : graph[u]) {
                                if (e.to == v) {
                                    e.flow += new_capacity;
                                    break;
                                }
                            }
                            for (Edge& e : graph[v]) {
                                if (e.to == u) {
                                    e.flow -= new_capacity;
                                    break;
                                }
                            }
                            v = u;
                        }
                        break;
                    }
                    q.push({next, new_capacity});
                }
            }
        }
        if (parent[sink] == -1) break;
    }
    return flow;
}

int main() {
    int N, M;
    cin >> N >> M;
    int source, sink;
    cin >> source >> sink;

    graph.resize(N);
    parent.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u - 1].push_back({v - 1, c, 0});
        graph[v - 1].push_back({u - 1, 0, 0});
    }

    int max_flow = maxFlow(source - 1, sink - 1);
    cout << max_flow << endl;

    return 0;
}
