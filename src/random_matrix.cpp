#include<bits/stdc++.h>
using namespace std;

int c[100][100];
 
int main(){
	srand(time(NULL));
	int n=14;
	for(int i=1; i<=n; i++)
	{
		for (int y=1; y<=n; y++) 
		{	
			if (i == y) c[i][y]=0;
			else c[i][y] = rand();
			cout << c[i][y] << " ";
		}
	}
	// for (int i=1; i <= n; i++) cout << xopt[i] << " ";
	// cout << x[1];

}