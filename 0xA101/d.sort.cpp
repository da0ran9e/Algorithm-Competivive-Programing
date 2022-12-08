#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];

void merge(int l, int r, int mid)
{
	int l_sz = mid - l + 1;
	int L[l_sz + 1];
	int r_sz = r - mid;
	int R[]
}


int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	for(int i=0; i<n; ++i){
		int mindIndex=i;
		for(int j = i+1; j<n; ++j){
			if(a[j]<a[mindIndex]){
				mindIndex = j;
			}
		}
		swap(a[i], a[mindIndex]);
	}
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
}