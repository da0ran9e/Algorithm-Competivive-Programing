#include<bits/stdc++.h>
using namespace std;

bool check_phone_number(string str)
{
	int n = str.length();

	if(n != 10) return 0;
	for(int i = 0; i < 9; i++)
		if(!isdigit(str[i]))
			return 0;

	return 1;
}

int count_time_duration(string ftime, string etime)
{
	int ftimes = 3600*((ftime[0]-'0')*10+(ftime[1]-'0'))+60*((ftime[3]-'0')*10+(ftime[4]-'0'))+(ftime[6]-'0')*10+(ftime[7]-'0');
	int etimes = 3600*((etime[0]-'0')*10+(etime[1]-'0'))+60*((etime[3]-'0')*10+(etime[4]-'0'))+(etime[6]-'0')*10+(etime[7]-'0');
	return (etimes-ftimes);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	map <string, int> numberCalls;
	map <string, int> duraCall;
	int total_call = 0;
	bool resultCheckPhone = 1;
	string sign;
	string query;
	string fnum, tnum, date, ftime, etime;
	do
	{
		cin >> sign;
		if(sign == "#") continue;
		cin >> fnum >> tnum >> date >> ftime >> etime;
		resultCheckPhone = check_phone_number(fnum) || check_phone_number(tnum);
		total_call ++;
		numberCalls[fnum] ++;
		duraCall[fnum]=duraCall[fnum] + count_time_duration(ftime, etime);


	}
	while(sign != "#");

	do
	{
		cin >> query;
		if (query == "#") continue;
		if (query == "?check_phone_number")
		{
			cout << resultCheckPhone << endl;
		}
		else if (query == "?number_calls_from")
		{
			string phone;
			cin >> phone;
			cout << numberCalls[phone] << endl;
		}
		else if (query == "?number_total_calls")
		{
			cout << total_call << endl;
		}
		else if (query == "?count_time_calls_from")
		{
			string phone;
			cin >> phone;
			cout << duraCall[phone] << endl;
		}
	}
	while (query != "#");
}
