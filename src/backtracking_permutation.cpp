#include<bits/stdc++.h>
using namespace std;


int n;
int a[100];
void record()
{
	for(int i=1; i<=n; i++) cout << a[i] << " ";
		cout<<endl;
}
bool check(int y, int k)
{
	for(int j = 1; j < k-1; j++)
		if (y == a[j]) return 0;
	return 1;
}
void Try(int k) 
{

	for (int y=1; y<=n; y++)
	{
		if (check(y,k))
		a[k]=y;
		if (k==n) record();
		else Try(k+1);
	}
}
int main(){n=3; Try(1);}