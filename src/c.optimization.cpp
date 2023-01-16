#include<bits/stdc++.h>
using namespace std;

int x[100];
int xopt[100];
c[100][100];
int visited[100];
int n, M, M1;
int fopt;

void Try(int k)
{
	for(int i=2; i<n; i++)
	{
		if (visited[i]==0)
		{
			x[k] = y;
			visited[i]=1;
			int cost = cost + c[x[n]][1];
			if (k==n)
				{ 
					int cost1 = cost + c[x[n]][1];
					if (fopt > cost1) 
						{
							fopt = cost1;
							for(int j=1; j<=n; j++) xopt[j] = x[j]
						}
				}
			else Try(k+1);
			visited[i]=0;
		}
	}
}

int main(){
	n = 5;
	for(int i=2; i<=n; i++) visited[i]=0;
		visited[1]=1;
	Try(2);
	cout << " the best path is:";
	for(int i=1; i<=n; i++)
}