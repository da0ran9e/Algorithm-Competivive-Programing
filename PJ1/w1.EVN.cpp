#include <bits/stdc++.h>
using namespace std;

float old_bill(int amount){
	if(amount>=0 && amount<=50)
		return (float)amount*1728;
	else if(amount>=51 && amount <=100)
		return 50*1728+(float)(amount-50)*1786;
	else if(amount>=101 && amount<=200)
		return 50*1728+50*1786+(float)(amount-100)*2074;
	else if(amount>=201 && amount <=300)
		return 50*1728+50*1786+100*2074+(float)(amount-200)*2612;
	else if(amount>=301 && amount<=400)
		return 50*1728+50*1786+100*2074+100*2612+(float)(amount-300)*2919;
	else	
		return 50*1728+50*1786+100*2074+100*2612+100*2919+(float)(amount-400)*3015;
}

float vat(float bill){
	return bill + bill/10;
}

float new_bill(int amount){
	if(amount>=0 && amount<=100)
		return (float)amount*1728;
	else if(amount>=101 && amount <=200)
		return 100*1728+(float)(amount-100)*2074;
	else if(amount>=201 && amount <=400)
		return 100*1728+100*2074+(float)(amount-200)*2612;
	else if(amount>=401 && amount<=700)
		return 100*1728+100*2074+200*2612+(float)(amount-400)*3111;
	else	
		return 100*1728+100*2074+200*2612+300*3111+(float)(amount-700)*3457;
}

int main(){
	int amount;
	cin >> amount;
	printf("%.2f", -vat(old_bill(amount))+vat(new_bill(amount))) ;
}