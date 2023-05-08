#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,c;
	int cnt = 0;
	cin >> n;
	int a[n]={0};
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		if (a[i-2]!=a[0])
		if (a[i-2]<a[i-1] && a[i-1]>a[i]) cnt++;
	}
	cout << cnt;
}