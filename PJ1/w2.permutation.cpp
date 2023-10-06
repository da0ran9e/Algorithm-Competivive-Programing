#include <bits/stdc++.h>
using namespace std;

#define NMAX 100

int x[NMAX];
bool existed[NMAX];

void Try(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (!existed[i]) { // check if i has been existed or not
            x[k] = i;
            existed[i] = true;

            if (k == n) {
                for (int j = 1; j <= n; j++)
                    cout << x[j] << " ";
                cout << endl;
            } else {
                Try(k + 1, n);
            }
            existed[i] = false;
        }
    }
}

int main(){
    int n;
    cin >> n;
    Try(1, n);
}