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
// 		int N;
// 	cin >> N;
// 	vector<vector<int>> v;
// 	for (int i=0; i<N; ++i)
// 	{
// 		int n;
// 		cin >> n;
// 		v.push_back(vector<int> ());
// 		for(int j=0; j<n; ++j)
// 		{
// 			int x;
// 			cin >> x;
// 			v[i].push_back(x);

// 		}
// 	}
	
// 	for(int i=0; i<v.size(); ++i){
// 		printVec(v[i]);
// 	}
// 	cout << v[0][1];
// }

	int N;
	cin >> N;
	vector<vector<int>> v;
	for (int i=0; i<N; ++i)
	{
		int n;
		cin >> n;
		vector<int> temp;
		for(int j=0; j<n; ++j)
		{
			int x;
			cin >> x;
			temp.push_back(x);

		}
		v.push_back(temp);
	}
	v[0].push_back(10);
	v.push_back(vector<int> ());
	for(int i=0; i<v.size(); ++i){
		printVec(v[i]);
	}
	cout << v[0][1];
}