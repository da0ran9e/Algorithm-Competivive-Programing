#include<bits/stdc++.h>
using namespace std;

int burteForce(int *s, int r)
{
	int d;
	int l=0;

	for (int i=0; i<r; i++)
	{
		d=0;
		for (int j=0; j<r; j++)
		{
			d+=abs(s[i]-s[j]);
		}
		if (l>d || i==0)
		{
			l=d;
		}
	}
	return l;
}

int median(int *s, int r)
{
	sort(s, s+r);
	int m = s[r/2];
	int l=0;
	for(int i=0; i<r; i++){
		l+=abs(s[i]-m);

	}
	return l;
}

main(){
	int t;
	int r;

	cin >> t;
	while(t--)
		{
			cin >> r;
			int s[r];
			for (int i=0; i<r; i++)cin >> s[i];
			cout << burteForce(s, r) << " ";
			cout << median(s, r) << endl;
		}
}