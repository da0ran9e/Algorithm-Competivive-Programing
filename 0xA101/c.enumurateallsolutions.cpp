#include<bits/stdc++.h>
using namespace std;

int x[100];
int M, n, M1;

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
	int U=M-M1-(n-k);
	for (int i=1; i<= U; i++)
	{
		x[k]=i;
		M1=M1+x[k];
		if(k==n)
		{
			if(M1==M) Print();
		}
		else Try(k+1);
		M1=M1-x[k];
	}
}

int main(){
	n=3;
	M=5;
	Try(1);
	M1=0;

}