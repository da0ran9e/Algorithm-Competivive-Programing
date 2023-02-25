#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;

#define max 1000006
int n, m, a[maxn], M[maxn][21];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i] ;
		M[i][0]=a[i];
	}
	for(int j=1; (1<<j) <=n; j++)
		for (int i=1;i+(1<<j)-1<=n; i++)
			M[i][j]=min(M[i][j-1], M[i+(1<<(j-1))][j-1]);
		cin >> m;
		long long sum = 0;
		for (int t=1; t<=m; t++)
		{
			int i, j;
			cin >> i >> j;
			i++; 
			j++;
			int k = log2(j-i+1);
			int u = i;
			int v = j - (1<<k) + 1;
			sum += min(M[u][k], M[v][k]);
		}
		cout << sum;
}