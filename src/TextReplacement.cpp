// AI
// Artificial Intelligent
// Recently, AI is a key technology. AI enable efficient operetions in many fields.

#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1 , s2 , t;
	getline(cin,s2);
	getline(cin,s1);
	getline(cin, t);
	
	string buf;
	size_t pos=0;
	size_t prePos;

	buf.reserve(t.size());

	while(true) {
		prePos = pos;
		pos = t.find(s2, pos);
		if (pos == string::npos){
			break;
		}
		buf.append(t, prePos, pos - prePos);
		buf+=s1;
		pos+=s2.size();

	}
buf.append(t, prePos, t.size() - prePos);
t.swap(buf);


cout << t << endl ;



	
}