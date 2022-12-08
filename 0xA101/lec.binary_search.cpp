#include<bits/stdc++.h>
using namespace std;

int Binary_search(int *sum, int low, int high, int target)
{
	while(low <= high)
	{
		int mid = (low+high)/2;
		if (sum[mid] == target) return mid;
		else if (sum[mid] < target)low = mid + 1;
		else high = mid - 1;
	}
	return high;
}

int main(){
	int n, t;
	cin >> n >> t;
	int time[n+1];
	int sum[n+1];
	cin >> time[1];
	sum[1] = time[1];

	for (int i =2; i<=n; i++)
	{
		cin >> time[i];
		sum[i]=time[i]+sum[i-1];
	}
	int result = 0;
	for (int i=1; i<=n; i++)
	{
		int j=Binary_search(sum, i, n, t+sum[i]-time[i]);
		result = max(result, j-i+1);
	}
	cout << result;

}