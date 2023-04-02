#include<bits/stdc++.h>
using namespace std;

void Permutation(int a[], int n)
{
	sort(a, a+n);
	while(next_permutation(a, a+n))
	{
		for(int i=0; i<n; i++)
			{cout << a[i] << " ";}
		cout << endl;
	}
}

int main(){
	int a[10];
	int n;
	while(true)

	{
		for(int n=0; n>=0; n++){
			int a[n];
			cin >> a[n];
		// if (a[n]==NULL) break;
		}

	}
	n--;
	Permutation(a, n);
}