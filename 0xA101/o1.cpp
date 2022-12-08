/* 
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int m=pow(2, n);

	char b[n];

	while(m--){
			for(int i=0; i<n; i++){
			b[i] = '1';
		
		}
		cout << b << endl;

	}

}