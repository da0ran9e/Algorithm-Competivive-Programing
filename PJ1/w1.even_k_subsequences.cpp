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

// Example:
//6 3
//2 4 5 1 1 2
//
// Initialize sum array:
//      [sum]    0  0  0  0  0  0 ...
// Input array:
//       [x]     2  4  5  1  1  2
//      sum[i-1]   ~v~~^~  x[i]
//            sum[i]  ~v~
//      [sum]    2  6  11 12 13 15 ...
// int seq_sum = sum[i] - (i>=k ? sum[i-k]:0)
//     seq_sum   -  -  11 10 7  4
//     count++         ~~~^~~~~~^~ 2
