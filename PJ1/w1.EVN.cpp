#include <bits/stdc++.h>
using namespace std;

#define VAT(a) a+a/10;

float odd_bill(int amount){
	if(amount>=0 && amount<=50)
		return (float)amount*1.728;
	else if(amount>=51 && amount <=100)
		return (float)amount*1.786;
	else if(amount>=101 && amount<=200)
		return (float)amount*2.074;
	else if(amount>=201 && amount <=300)
		return (float)amount*2.612;
	else if(amount>=301 && amount<=400)
		return (float)amount*2.919;
	else	
		return (float)amount*3.015;
}

float new_bill(int amount){
	if(amount>=0 && amount<=100)
		return (float)amount*1.728;
	else if(amount>=101 && amount <=200)
		return (float)amount*2.074;
	else if(amount>=201 && amount <=400)
		return (float)amount*2.612;
	else if(amount>=401 && amount<=700)
		return (float)amount*3.111;
	else	
		return (float)amount*3.457;
}

int main(){
	int amount;
	cin >> amount;
	cout << VAT(odd_bill(amount)) - VAT(new_bill(amount));
}