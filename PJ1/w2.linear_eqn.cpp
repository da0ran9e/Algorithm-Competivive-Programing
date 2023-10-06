#include <bits/stdc++.h>
using namespace std;

#define NMAX 100

int sum;
int temp = 0;
int x[NMAX];

bool check(int now){
    // check if the solution is correct or not
    if (now + temp != sum) return false;
    return true;
}

void Try(int k, int n){
    for(int i = 1; i <= sum - temp - (n-k)/*continue while have not reach the solution*/; i++){
        if (k==n) if(!check(i)) continue;
            x[k] = i;
            temp += i; // save the found solutions sum to check the next once
            if(k == n) {
                for(int j = 1; j <= n; j++)
                    cout << x[j] << " ";
                cout << endl;
            }
            else Try(k+1, n);
            temp -= i; //return to the previous solution point
    }
}

int main(){
    int n;
    cin >> n >> sum;
    Try(1, n);
}