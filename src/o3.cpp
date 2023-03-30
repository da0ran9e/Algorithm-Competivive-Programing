/*
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n;
	int a[21], s[21];

	k=1;
	s[k]=0;
	while (k>0)
	{
		while (s[k]<=1)
		{
			a[k]=s[k];
			s[k]=s[k]+1;
			if (k==n)
				{for(int i=1; i<=n ;i++)
					{cout << a[i];
					}
	
				}
			else
			{
				k++, s[k]=0;
			}

		}
		k--; 
	}

}