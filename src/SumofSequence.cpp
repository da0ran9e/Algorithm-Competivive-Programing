#include<bits/stdc++.h>
using namespace std;

string Sum(string a, string b)
{
	int sum, lastDigit;
	string result;
	int r=0;

	while(a.size()<b.size()) a="0"+a;
	while(a.size()>b.size()) b="0"+b;

	for(int i=a.size()-1; i>=0; i--)
	{
		sum = (a[i]-'0')+(b[i]-'0')+r;
		r=sum/10;
		lastDigit = sum%10;
		result = to_string(lastDigit) + result;
	}
	if (r==1) result = "1" + result;
	return result;
}

int main (){
	int n;
	string sum;
	cin >> n;
	string a[n];

	for(int j=0; j<n; j++) cin >> a[j];
		// for(int j=0; j<n; j++) cout << a[j] << " ";
		// 	cout << endl;
		for(int t=0; t<n-1; t++)
			{
				sum = Sum(a[t], a[t+1]);
				// cout << sum << endl;
				a[t+1] = sum;

			}
			cout << sum << endl;
	return 0;
}