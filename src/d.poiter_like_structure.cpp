#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v={2,3,5,6,7};
	for(int i=0; i<v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	vector<int> ::iterator it = v.begin();
	cout << (*(it+1)) << endl;
	for(it=v.begin(); it!=v.end(); it++)
	{
		cout << (*it) << endl;
	}

	vector<pair<int, int>> v_p = {{1,2},{2,3},{3,4},{4,5}};
	vector<pair<int, int>>::iterator itt;
	for(itt=v_p.begin(); itt!=v_p.end();itt++)
	{
		cout << (itt->first) << " " << (itt->second) << endl;
		//(*it).first == (it->first)
	}
}