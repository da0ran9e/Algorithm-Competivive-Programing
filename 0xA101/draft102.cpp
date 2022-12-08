#include<bits/stdc++.h>
using namespace std;

int main (){
	int n, k;
	int a[20], s[20];
	cin >> n;


	k=1;
	s[k]=0;
	while(k>0){
		
			s[k]=a[k];
			a[k]=s[k]+1;
			
		if(k==n){for(int i=1; i<=n; i++){
				cout << a[i];
			
		}
		cout<<endl;
		k++;

		}
		else{
			k--;
			s[k]=0;
		}
	}
}