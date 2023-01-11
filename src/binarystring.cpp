#include<bits/stdc++.h>
using namespace std;

int a[100];
int n;
void record()
{
	for(int i=1; i<=n; i++){cout << a[i];}
		cout << endl;
}

void binary(int b)
{
	for(int i=0; i<=1; i++)
	{
		a[b] = i;
		if (a[b] == n) record();
		else binary(b+1);
	}
}
int main()
{
 cin >> n;
 binary(1);
}