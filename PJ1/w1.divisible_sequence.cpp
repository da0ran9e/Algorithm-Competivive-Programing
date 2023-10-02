#include <bits/stdc++.h>
using namespace std;

void check(int n){
	for (int i=100; i<1000; i++) if (i%n == 0) cout << i << " ";
}

int main(){
	int n;
	cin >> n;
	check(n);
}