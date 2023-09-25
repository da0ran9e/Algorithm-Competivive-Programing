#include<bits/stdc++.h>
using namespace std;

int n;
int c[100][100];
int x[100];
int xopt[100];
bool visited[100] = {0};
int f=0;
int fopt=INT_MAX;
int c_min = INT_MAX;

void Try(int k)
{
	for(int i=2; i<=n; i++)
	{
		if(visited[i]==0)
		{
			x[k]=i;
			visited[i]=1;
			f=f+c[x[k-1]][x[k]];
			if(k==n)
			{
				int f1 = f + c[x[k]][x[1]];
				if (f1 < fopt) 
				{	
					fopt=f1;
					for(int j=1; j<=n; j++) xopt[j] = x[j];
				}

			}
			else {
				int g = f + c_min * (n-k+1);
				if (fopt > g) 
					Try(k+1);
			}
			visited[i]=0;
			f=f-c[x[k-1]][x[k]];

		}
	}
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		for (int y=1; y<=n; y++) 
		{
			cin >> c[i][y];
			if (i != y)
				if (c[i][y] < c_min)
					c_min = c[i][y];
		}
	}
	x[1]=1;
	Try(2);
	cout << fopt << endl;
	// for (int i=1; i <= n; i++) cout << xopt[i] << " ";
	// cout << x[1];

}
// 5
// 0 3 14 18 15 
// 3 0 4 22 20
// 17 9 0 16 4 
// 9 20 7 0 18
// 9 15 11 5 0
