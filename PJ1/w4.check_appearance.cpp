#include<bits/stdc++.h>
using namespace std;

#define NMAX 10000

int main(){
	int n;
	vector<int> arr(n);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}

	for (int i=0; i<n; i++){
	int a = 0;	
		for (int j=0; j<i; j++){
			if (find(arr(i), arr.end(), arr[i]) != arr.end()) {
				a=1;
				break;
			}
		}
		cout << a << endl;
	}
}