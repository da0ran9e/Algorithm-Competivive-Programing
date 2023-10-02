#include <bits/stdc++.h>
using namespace std;

bool check_date(string date){
	if (date.length()!=10 || date[4]!=':' || date[7]!=':') return false; //syntax checker

	int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
	int month = (date[5]-'0')*10 + (date[6]-'0');

	if (month>12) return false;
	switch(month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 11:
		if ((date[8]-'0')*10 + (date[9]-'0')>31) return false;
		break;
	case 2:
		if ((date[8]-'0')*10 + (date[9]-'0')>29) return false;
		if (year%4 == 0) if ((date[8]-'0')*10 + (date[9]-'0')>28) return false;
		break;
	default:
		if ((date[8]-'0')*10 + (date[9]-'0')>30) return false;
	}
	
	return true;
}

int year(string date){
	return (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
}

int month(string date){
	return (date[5]-'0')*10 + (date[6]-'0');
}

int day(string date){
	return (date[8]-'0')*10 + (date[9]-'0');
}

void print_date(string date){
	cout << year(date) << " " << month(date) << " " << day(date);
}

int main(){
	string date;
	cin >> date;
	if (check_date(date))
		print_date(date);
	else cout << "INCORRECT";
}