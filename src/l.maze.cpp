#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
queue<ii> Q;
const int maxN = 1001;
const int oo = 1e9 +7;
int m,n,r,c;
int A[maxN][maxN];
int visited[maxN][maxN];
int step[maxN][maxN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int BFS(int r, int c)
{
	Q.push(ii(r,c));
	visited[r][c] = 1;
	step[r][c] = 0;
	while(!Q.empty())
	{
		ii u = Q.front();
		Q.pop();

		int x = u.first;
		int y = u.second;

		for(int i=0; i<4; i++)
			{
				int x1 = x + dx[i];
				int y1 = y + dy[i];
				if(x1<1 || x1>m || y1<1 || y1>n) return step[x][y]+1;
				if (visited[x1][y1]==0 && A[x1][y1] == 0) 
					{
						Q.push(ii(x1, y1));
						step[x1][y1] = step[x][y]+1;

					}
			}
	}
	return -1;
}

int main(){
	cin >> m >> n >> r >> c;
	for(int i=1; i <= m; i++)
		for (int j=1; j<=n; j++) cin >> A[i][j];
	int result = BFS(r,c);
cout << result;
}
// 8 12 5 6
// 1 1 0 0 0 0 1 0 0 0 0 1
// 1 0 0 0 1 1 0 1 0 0 1 1
// 0 0 1 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 1 0 0 1 0 1
// 1 0 0 1 0 0 0 0 0 1 0 0
// 1 0 1 0 1 0 0 0 1 0 1 0
// 0 0 0 0 1 0 1 0 0 0 0 0
// 1 0 1 1 0 1 1 1 0 1 0 1