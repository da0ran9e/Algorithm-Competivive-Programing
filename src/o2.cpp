#include<bits/stdc++.h>
using namespace std;


string Sum(string a,string b){
	while (a.size() < b.size()) {a="0"+a;}
	while (b.size() > b.size()) {b="0"+b;}
		int sum;
		int mem=0;
		string result;
	for (int i=a.size()-1; i>=0; i--){
		sum = (a[i]-'0')+(b[i]-'0')+mem;
		mem = sum/10;
		int lastDigit = sum%10;
	
		result = to_string(lastDigit) + result;
		//result.push_back(lastDigit + '0');


	}
	if (mem == 1){
		result='1'+result;
	}

	return result;
}
int main()
{
	string a, b;
	cin >> a >> b;
	cout << Sum(a, b) << endl;

}