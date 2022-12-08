#include<bits/stdc++.h>
using namespace std;

int a[100], x[100];
int M, n, M1, M2;
int cnt=0;

void Print()
{
	cout<<"(";
	for(int i=1; i<=n; i++){
		cout << x[i] << " ";
	}
	cout << ")" << endl;
}

void Try(int k)
{
	int L = 1;
	int U=(M-M1-M2)/a[k];
	for (int i=1; i<= U; i++)
	{
		x[k]=i;
		M1 += a[k]*x[k];
		M2 -= a[k+1];
		if(k==n)
		{
			if(M1==M)
			{
				cnt ++;
				//Print();
			}

		}
		else Try(k+1);
		M1 -= a[k]*x[k];
		M2 += a[k+1];
	}
}

int main(){
	cin >> n >> M;
	for (int i=1; i<=n; i++) cin >> a[i];
	M1=0;
	M2=0;
	for (int i=2; i<=n; i++) M2 += a[i];
	Try(1);
	cout << cnt;
}