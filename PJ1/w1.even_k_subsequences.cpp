#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int main(){
	int n, k, x[MAX_N];
	int count=0;
	cin >> n >> k;
	for (int i = 0; i<n; i++){
		cin >> x[i];
		if(i>=k){
			int sum=0;
			for(int j=k; j>0; j--) {
				sum+=x[i-j];
			}
			if(sum%2==0) count++; 
		}
	}
	cout << count;
}