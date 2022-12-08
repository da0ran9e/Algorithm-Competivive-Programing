#include<bits/stdc++.h>
using namespace std;


int n;
int a[100];

bool CheckNotFinal()
{
	for(int i=1; i<=n; i++)
	{
		if(a[i-1] < a[i]) return 0;
	}
	return 1;
}

void printSolution(){
	cout << "(";
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n-1)
			cout << ", ";
	}
	cout << ")\n";
}

void Swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Next_Generate() {
	int j = n-1;
	while (a[j] > a[j+1]) {
		j = j-1;
	}

		// #Step 2: Find akbeing smallest number among those on the rightajand greater thanaj:
	int k = n;
	while (a[j] > a[k]) {
		k = k-1;
		Swap(&a[j], &a[k]);
	}

	//#Step 3: Invert the sequenceaj+1 toan:
	int r = n;
	int l = j+1;
	while (r > l) {
		Swap(&a[r], &a[l]);
		r = r-1;
		l = l+1;
	}

	printSolution();
}

void Generate(){
	while (!CheckNotFinal()){
		Next_Generate();
	}
	return;
}


int main(){
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	Generate();
}