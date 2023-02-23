#include <bits/stdc++.h>
using namespace std;

string g;
string g1 = "A";
string g2 = "B";
int loc;
int n, i;

int FindIndex(int i)
{
	int len1=1;
	int len2=1;
	int len;
	int k;

	for(k=3; len<i; k++)
	{
		len = len1 + len2;
		len1 = len2;
		len2 = len;
	}
	return k;
}

void Fibonacci(int n, int i)
{
	int k=FindIndex(i);
	for (int j=3; j<=k; j++)
		{
			g=g1+g2;
			g1=g2;
			g2=g;
		}
	if (i<=strlen(g1)) cout << g[i+3];
	if (i>strlen(g1)) cout << g[i+g1.size()+3];
}
int main(){
	cin >> n >> i;
	Fibonacci(n, i);
	return 0;
}