#include <bits/stdc++.h>
using namespace std;

#define NMAX 9999

int Imax=INT_MIN;
int Imin=INT_MAX;
int sum=0;
int arr[NMAX];

void check_max(int x){
	if(x>Imax){
		Imax = x;
	}
}

void check_min(int x){
	if(x<Imin){
		Imin = x;
	}
}

int max_segment(int x, int y){
	int max_seg=INT_MIN;
	for (int i=x-1; i<y; i++){
		if(arr[i]>max_seg) max_seg = arr[i];
	}
	return max_seg;
}

int main(){
	int n;
	cin >> n;

	for (int i=0; i<n; i++){
		cin >> arr[i];
		sum+=arr[i];
		check_max(arr[i]);
		check_min(arr[i]);

	}

	string line;
	do{
		cin >> line;
		if (line[0] == '*') continue;

		else if (line == "find-max") cout << Imax << endl;
		else if (line == "find-min") cout << Imin << endl;
		else if (line == "sum") cout << sum << endl;
		else if (line == "find-max-segment") {
			int x, y;
			cin >> x >> y;
			cout << max_segment(x, y) << endl;
		}
	} while(line!="***");
}