#include<bits/stdc++.h>
using namespace std;

int m=1e9+7;
int combination(int n,int k)
{
	k = min(k, n-k);
	int a[k], b[k], g;
	long long result=1;
	iota(a, a+k, n-k+1);
	iota(b, b+k, 1);

	for(int i=0; i<k; i++)
		for(int j=0; j<k; j++)
	{
		if(b[i]==1) break;
		g=__gcd(b[i], a[j]);
		a[j]=a[j]/g;
		b[i]=b[i]/g;

	}
	for(int i=0; i<k; i++)
	{
		result = (result*a[i])%m;
	}
	return result;
}
int main (){
	int k, n;
	cin >> k >> n;
	cout << combination(n, k);

}