#include<bits/stdc++.h>
using namespace std;

int a[100];
int n;
int cnt;

void record()
{
	cnt++;
	cout << '(';
	for(int i=1; i<=n; i++)
		cout << a[i] << ',';
	
	cout << '\b' << ')' <<endl;
}

bool check(int k, int y )
{
	for (int j=1; j<=k-1; j++)
		if (y==a[j] || abs(k-j) == abs(y-a[j]))
			return 0;

	return 1;
}
 void Try(int k)
 {
 	for (int y=1; y<=n; y++)
 	{
	 	if(check(k,y)){
	 		a[k]=y;
	 		if (k==n) record();
	 		else Try(k+1);
	 	}
 	}
 }

int main(){n=5; Try(1);
	if (cnt == 0) cout << "no solution";}