#include<bits/stdc++.h>
using namespace std;

#define nmax 100007

int n, m, eh, hh, h;
int sh=0;
int a[nmax];
int highest=0;
int cutted=0;
int available=0;

void Cut()
{
	h = (eh + sh)/2;
	if (h!=eh)
		{
			for(int i=1; i<=n; i++)
				{
					if (a[i] > h) cutted += a[i]-h;
				}
				if (cutted = m) hh = h;
				else if ( cutted > m){
					hh=h;
					sh=h;
					Cut();
				}
				else {
					eh=h;
					Cut();
				}
		}
}

int main(){
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		if(a[i]>highest) highest=a[i];
		available += a[i];
	}
	if (m>available) cout << "Do not enough wood!";
	eh=highest;
	Cut();
	cout << hh;
}