#include<bits/stdc++.h>
using namespace std;
#define NMAX 32

int n, m;
int conflict[NMAX][NMAX]={0};
int canTeach[NMAX][NMAX]={0};
int assigned[NMAX];
int load[NMAX]={0};
int fopt;
int maxload[NMAX]={0};

void print(int k)
{
	for (int i=1; i<=k; i++)
	{
		cout << assigned[i] << " ";
	}
	cout << endl;
}

bool check(int k, int i)
{
	if (canTeach[i][k]==0) return 0;
	for (int j=1; j<=k; j++)
	{
		if (assigned[j]==i && conflict[j][k]==1) return 0;
	}
	return 1;
}

void Try(int k)
{
	for(int i=1; i<=n; i++)
	{
		if ( check(k, i))
		{
			assigned[k] = i;
			load[i]++;
			maxload[k] = max(maxload[k-1], load[i]);
			if (k==n)
			{
				print(k);
				if (fopt > maxload[n]) fopt = maxload[n];
			}
			else if (maxload[k] < fopt)
				Try(k+1);
			load[i]--;
		}
	}
}

int main()
{
	int s,t;
	int k, t1, t2;
	fopt = INT_MAX;
	cin >> m >> n;
	for (int i=1; i<=m; i++)
	{
		cin >> s;
		for (int j=1; j<=s; j++)
		{
			cin >> t;
			canTeach[i][t]=1;
		}

	}
	cin >> k;
	for (int i=1; i<=k; i++)
	{
		cin >> t1 >> t2;
		conflict[t1][t2]=1;
		conflict[t2][t1]=1;

	}
	Try(1);
	cout << fopt << endl;

}