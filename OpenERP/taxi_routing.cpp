#include<bits/stdc++.h>
using namespace std;

int n;
int c[100][100];
int x[100];
int xopt[100];
bool visited[100] = {0};
int f=0;
int fopt=INT_MAX;
int c_min=INT_MAX;

void Try(int k)
{
	for(int i=1; i<=n; i++)
	{
		if(visited[i]==0)
		{
			x[k]=i;
			visited[i]=1;

			if (k==1)f=c[0][x[1]]+c[x[1]][x[1]+n];
			else f=f+c[x[k-1]+n][x[k]]+c[x[k]][x[k]+n];
			if(k==n)
			{
				int f1 = f + c[x[n]+n][0];
				if (f1 < fopt) 
				{
					fopt=f1;
					for(int j=1; j<=n; j++) xopt[j] = x[j];
				}

			}
			else 
			{
				if (f + (2*(n-k)+1)*c_min < fopt)
					Try(k+1);
			}

			visited[i]=0;
			if(k==1)f=0;
			else f=f-c[x[k-1]+n][x[k]]-c[x[k]][x[k]+n];

		}
	}
}
int main(){
	cin >> n;
	for(int i=0; i <= n * 2; i++)
	{
		for (int y=0; y <= n * 2; y++) {
			cin >> c[i][y];
			if (i != y && c_min > c[i][y])
				c_min = c[i][y];
		}

	}
	x[0]=0;
	Try(1);
	cout << fopt << endl;

}
// 2
// 0 8 5 1 10
// 5 0 9 3 5
// 6 6 0 8 2
// 2 6 3 0 7
// 2 5 3 4 0
