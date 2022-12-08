#include<bits/stdc++.h>
using namespace std;

int main(){
	string c;
	stack<int>a;
	int s;

	while(true)
	{
		cin >> c;
		if (c=="PUSH") 
		{
			cin >> s;
			a.push(s);
		}
		if (c=="POP")
		{
			if(a.empty()){cout << "NULL" << endl;}
			else{
				cout << a.top() << endl;
				a.pop();
			}
		}
		if (c=="#") break;
	}
return 0;

}