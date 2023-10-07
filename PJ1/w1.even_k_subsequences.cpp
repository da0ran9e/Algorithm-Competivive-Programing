#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int subarrays(int n, int k, int *x){
	int count = 0;
	int sum[MAX_N] = {0};

	for (int i=0; i<n; i++){
		sum[i] = sum[i-1] + x[i]; // 
	}

	for (int i=k-1; i<n; i++){
		int seq_sum = sum[i] - (i>=k ? sum[i-k]:0);
		if(seq_sum%2 == 0){
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
