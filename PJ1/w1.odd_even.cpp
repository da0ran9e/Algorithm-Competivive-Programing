#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a, odds=0, evens=0;
	for (int i=0; i<n; i++){
		cin >> a;
		if (a%2==0) evens ++;
		else odds++;	
	}
	cout << odds << " " << evens;
}