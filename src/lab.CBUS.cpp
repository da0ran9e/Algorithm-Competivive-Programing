#include<bits/stdc++.h>
using namespace std;

bool check(int i)
{
	if(i<=n)
}

void Try()
{
	for(int i=1; i<=2*n; i++)
	{
		if (check(k, i))
		{
			if (i<=n) cnt++;
			else cnt--;
			x[k] = i;
			visited[i]=1;
			f+=c[x[k+1]][x[k]];
			if(k==2+n)
			{
				int f1 = f + c[k][x[0]];
				if (f1 < fopt) fopt=f1;
			}
			else if (fopt > f+cmin*(2n-k+1))
				Try(k+1);
			visited[i]=0;
			f -= c[x[k-1]][x[k]];
			if (i<=n) cnt--;
			else cnt++;
		}
	}
}