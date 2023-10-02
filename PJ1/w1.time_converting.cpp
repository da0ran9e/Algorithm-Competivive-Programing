#include <bits/stdc++.h>
using namespace std;

int to_seconds(string time){
	return (((time[0]-'0')*10 + (time[1]-'0'))*3600 + ((time[3]-'0')*10 + (time[4]-'0'))*60 + (time[6]-'0')*10 + (time[7]-'0'));  
}

int main(){
	string time;
	cin >> time;
	cout << to_seconds(time);
}