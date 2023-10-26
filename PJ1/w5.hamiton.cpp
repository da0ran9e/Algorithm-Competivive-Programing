#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos, int n) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        return false;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1, n))
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

bool isHamiltonianGraph(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n, -1);
    path[0] = 0;

    if (hamiltonianCycleUtil(graph, path, 1, n))
        return true;

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
        }

        if (isHamiltonianGraph(graph))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}
