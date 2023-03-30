#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;

		int angles[n] = {0};
		int v;
		bool u=true;

		for(int i=0; i<m*m; i++)
		{
			cin >> v;
			angles[v-1]+=1;
			// cout << angles[v-1];
		}
		for(int i=0; i<n; i++)
		{
			if (angles[i]<2) u=false;
		}
		cout << u << endl;

	}
}