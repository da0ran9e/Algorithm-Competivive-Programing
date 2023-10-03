#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int subarrays(int n, int k, int *x){
	int count = 0;
	int f[MAX_N] = {0};

	for (int i=1; i<n; i++){
		f[i] = f[i-1] + x[i];
	}

	for (int i=k-1; i<n; i++){
		int sum = f[i] - (i>=k ? f[i-k]:0);
		if(sum%2 == 0){
			count ++;
		}
	}
	return count;
}

int main(){
	int n, k, x[MAX_N];
	cin >> n >> k;
	for (int i = 0; i<n; i++){
		cin >> x[i];
	}
	cout << subarrays(n,k,x);
}