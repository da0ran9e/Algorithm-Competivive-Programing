#include<bits/stdc++.h>
using namespace std;

void func(int n)
{
	if(n==0) return;
	cout << " " << n << endl;
	func(n-1);
	cout << n << endl;
}
int fact(int n) //n!
{
	if(n==0) return 1;
	return fact(n-1)*n;
}

int main(){
	func(5);
	cout << fact(5);
}