#include<bits/stdc++.h>
using namespace std;

#define NMAX 1000000

int main(){
	int n, arr[NMAX];
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	for (int i=0; i<n; i++){
		int cnt=0;
		for (int j=0; j<i; j++){
			if (arr[j]==arr[i]) cnt++;
		}
		cout << cnt << endl;
	}
}