#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v)
{
	cout << "size: " << v.size() << endl;
	for(int i=0; i<v.size(); ++i){
		//v.size()-> 0(1)
		cout << v[i] << " ";
	}
	cout << endl;
}

void printVec2(vector<int> &v)
{
	cout << "size: " << v.size() << endl;
	for(int i=0; i<v.size(); ++i){
		//v.size()-> 0(1)
		cout << v[i] << " ";
	}
	v.push_back(2);
	cout << endl;
}

int main(){
	vector<int> v;
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		int x; 
		cin >> x;
		printVec(v);
		v.push_back(x);
	}
	printVec(v);

	vector<int> vv(10,3);
	vv.push_back(7);
	printVec(vv);

	vector<int> v1;
	v1.push_back(7);
	v1.push_back(6);

	vector<int> &v2 = v1;
	v2.push_back(5);
	printVec2(v1);
	printVec2(v1);
	printVec2(v2);

}