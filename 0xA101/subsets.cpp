#include<bits/stdc++.h>
using namespace std;

int m,n;
int a[100];

void record()
{
	for(int i=1; i<=m; i++) cout << a[i] << " ";
		cout<<endl;
}

void Try(int k) 
{

	for (int y=a[k-1]+1; y<=n-m+k; y++)
	{
		a[k]=y;
		if (k==m) record();
		else Try(k+1);
	}
}
int main()
{
	cin >> n >> m;
	Try(1);
}