#include <bits/stdc++.h>
using namespace std;

int main(){
	queue<int> q;
	string command;
	int value;
	while (cin>>command && command!="#")
	{
	    if (command == "PUSH")
	    {
	        cin>>value;
	        q.push(value); 
	    }
	    else if (command == "POP")
	    {
	        if (q.empty()) 
	        {
	            cout<<"NULL"<<endl;
	        }
	        else
	        {
	            cout<<q.front()<<endl; 
	            q.pop();
	        }
	    }
	}
}