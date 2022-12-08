#include<bits/stdc++.h>
using namespace std;

void print(map<int,string> &m)
{
	cout << m.size() << endl;
	for(auto &pr:m){
		cout << pr.first << " " << pr.second << endl;
	}
}
int main(){
	map<int, string>  m;
	m[1] = "abc"; //O(log(n))
	m[5] = "bcd";
	m[3] = "cde";
	m.insert({4, "afg"});
	m[6];
	m[5] = "xxx";
	auto it = m.find(3);
	m.erase(it);
	if(it == m.end()){
		cout << "No value";
	}else{
		cout << (*it).first << " " << (*it).second << endl;
	}

	// map<int,string> ::iterator it;
	// for(it = m.begin(); it!=m.end(); ++it){
	// 	cout << (*it).first << " " << (*it).second << endl;
	// }

	// for(auto &pr:m){
	// 	cout << pr.first << " " << pr.second << endl;
	// }
	m[4]+"aa";
	print(m);
	m.clear();
	print(m);
}