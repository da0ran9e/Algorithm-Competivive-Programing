#include <bits/stdc++.h>
using namespace std;

bool check_time(string time){
	if (time.length()!=8 || time[2]!=':' || time[5]!=':') return false; //syntax checker
	if ((time[0]-'0')*10 + (time[1]-'0') > 24 ) return false; //hours checker
	if ((time[3]-'0')*10 + (time[4]-'0') >= 60 ) return false; //minutes checker
	if ((time[6]-'0')*10 + (time[7]-'0') >= 60 ) return false; //minutes checker
	return true;
}

int to_seconds(string time){
	return (((time[0]-'0')*10 + (time[1]-'0'))*3600 + ((time[3]-'0')*10 + (time[4]-'0'))*60 + (time[6]-'0')*10 + (time[7]-'0'));  
}

int main(){
	string time;
	cin >> time;
	if (check_time(time))
		cout << to_seconds(time);
	else cout << "INCORRECT";
}