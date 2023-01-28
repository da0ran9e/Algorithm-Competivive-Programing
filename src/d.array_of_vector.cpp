#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
	cout << "size: " << v.size() << endl;
	for(int i=0; i<v.size(); ++i){
		//v.size()-> 0(1)
		cout << v[i] << " ";
	}
	cout << endl;
}
int main(){
	//vector<pair<int,int>> v ={{1,2},{3,4},{5,6}};

	// vector<pair<int,int>>v;
	// printVec(v);
	// int n;
	// cin >> n;
	// for(int i=0; i<n; ++i){
	// 	int x, y;
	// 	cin >> x >> y;
	// 	v.push_back({x,y});
	// }
	// printVec(v);

	int N;
	cin >> N;
	vector<int> v[N];
	for (int i=0; i<N; ++i)
	{
		int n;
		cin >> n;
		for(int j=0; j<n; ++j)
		{
			int x;
			cin >> x;
			v[i].push_back(x);

		}
	}
	for(int i=0; i<N; ++i){
		printVec(v[i]);
	}
	cout << v[0][1];
}