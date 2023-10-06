#include <bits/stdc++.h>
using namespace std;

#define NMAX 100

int x[NMAX];

bool check(int prev, int now){
    // check if this bit and the previous are '1's or not
    if (now != 1) return false;
    if (prev != 1) return false;
    return true;
}

void Try(int k, int n){
    for(int i = 0; i <= 1; i++){
        if (check(x[k-1], i)) continue;
            x[k] = i;
            if(k == n) {
                for(int j = 1; j <= n; j++)
                    cout << x[j] << " ";
                cout << endl;
            }
            else Try(k+1, n);
    }
}

int main(){
    int n;
    cin >> n;
    Try(1, n);
}