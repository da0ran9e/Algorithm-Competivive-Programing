#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	set<int> s;
	map<int, int> m;
	for(int i=0; i<(int)(1e6); ++i)
	{
		// int x;
		// cin >> x;
		s.insert(rand());
	}
	for(int i=0; i<(int)1e5; ++i){
		auto it = s.lower_bound(rand());
		}
	// cout << (*it) << endl;

	// vector<int> a(n);
	// for(int i=0; i<n; ++i)
	// {
	// 	cin >> a[i];
	// }
	// sort(a.begin(), a.end());
	// for(int i=0; i<n; ++i)
	// {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	// auto it = upper_bound(a.begin(), a.end(), 5);
	// if(it==a.end()){
	// 	cout << (*it) << endl;
	// 	cout << "not found";
	// 	return 0;
	// }
	// cout << (*it) << endl;
}