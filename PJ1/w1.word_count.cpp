#include <bits/stdc++.h>
using namespace std;

int main(){
	char c;
	char temp;
	int cnt = 0;
	while(cin.get(c)){
		if((c==' ' || c=='\n') && ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9'))) cnt++;
		temp = c;
	}
	if((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9')) cnt++;
	cout << cnt;
}