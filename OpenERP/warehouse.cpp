#include<bits/stdc++.h>
using namespace std;

int n, T, D;
int t[1000], a[1000];
int f[1000][1000];
int res;
void proc()
{
	for (int i=1; i<=n; i++)
	{
		for(int k=t[i]; k<=T; k++)
		{
			for (int j=max(0, i-D); j<=i-1; j++)
			{
				f[i][k] = max(f[i][k], f[j][k-t[i]] + a[i]);
			}
			res = max(res, f[i][k]);
		}
	}
	cout << res << endl;
}
int main()
{
cin >> n >> T >> D;
for (int i=1; i<=n; i++) cin >> a[i];
for (int i=1; i<=n; i++) cin >> t[i];
proc();

}
