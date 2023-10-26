#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
bool g[N][N];
int t, n, m;
vector<int> path;

bool isValid(int v, int u) {
	if (g[v][u] == false) return false;
		for (int i = 0; i < path.size() - 1; i++)
	if (path[i] == v && path[i + 1] == u)
		return false;
		return true;
}

bool hamCycleUtil(int node) {
	if (node == n) {
	if (g[path[n - 1]][path[0]])
		return true;
	else
		return false;
	}

	for (int v = 0; v < n; v++) {
		if (isValid(node, v)) {
			path.push_back(v);
			if (hamCycleUtil(node + 1))
				return true;
			path.pop_back();
		}
	}
	return false;
}

bool isHamiltonianCycle() {
	if (hamCycleUtil(0) == false) {
		return false;
	}
	return true;
}

int main() {
	// cout << "Enter the number of graphs: ";
	cin >> t;
	while (t--) {
		// cout << "Enter the number of nodes in the graph: ";
		cin >> n;
		// cout << "Enter the number of edges in the graph: ";
		cin >> m;
		// cout << "Enter the adjacency matrix representation of the graph: " << endl;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = false;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			g[x][y] = g[y][x] = true;
		}
		path.clear();
		path.push_back(0);
		if (isHamiltonianCycle() == false)
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}
	return 0;
}




