#include<bits/stdc++.h>
using namespace std;

void bruteForce(int n, int price[], int span[]){
	for (int i = 0; i < n; i++)
		for(int j = i-1; j >= 0; j--)
			if (price[j] <= price[i])
				span[i]++;
			else
				break;

	return;
}
void Span(int n, int price[], int span[])
{
	stack<int>s;
	span[0]=0;
	s.push(0);


	for(int i=1; i<n-1; i++)
	{
		while(!s.empty() && price[i]>=price[s.top()])s.pop();
		if(s.empty())span[i]=i;
		else
		{
			span[i]=i-s.top()-1;
		}
		s.push(i);

	}
	return;
}

int main(){
	int n;
	cin >> n;
	int price[100] = {0};
	int span[100] = {0};

	for(int i=0; i<n; i++)
	{
		cin >> price[i];
	}
		Span(n, price, span);

	for(int i=0; i<n; i++)
	{
		cout << span[i] << " ";
		// Span(n, price, span);
		// cout << span[i] << " ";
	}
}