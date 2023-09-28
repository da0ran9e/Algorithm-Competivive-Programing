#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pos;
queue<pos> Q;

const int maxN = 1001;
int m, n, r, c;

int Maze[maxN][maxN];
int step[maxN][maxN];   // Save minimum numb3er of step from r c to i j

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int visited[maxN][maxN];

int BFS(int row, int col) {

    Q.push(pos(row, col));
    visited[row][col] = 1;
    step[row][col] = 0; // previously 0

    while (!Q.empty()) {
        pos now = Q.front();
        Q.pop();

        int x0 = now.first;
        int y0 = now.second;

        for(int i = 0; i < 4; i++) {
            int x1 = x0 + dx[i];
            int y1 = y0 + dy[i];

            if (x1 < 1 || x1 > m || y1 < 1 || y1 > n)
                return step[x0][y0] + 1;

            if (Maze[x1][y1] == 0 && visited[x1][y1] == false) {
                Q.push(pos(x1,y1));
                visited[x1][y1] = 1;
                step[x1][y1] = step[x0][y0] + 1;
            }
        }
    }

    return -1;
}


int main() {
    cin >> m >> n >> r >> c;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> Maze[i][j];

    int result = BFS(r,c);
    cout << result;

    return 0;
}
