#include <bits/stdc++.h>
using namespace std;

#define NMAX 100

int x[NMAX];
bool existed[NMAX];

void Try(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (!existed[i]) { // If integer i hasn't been existed yet
            x[k] = i;     // Choose integer i
            existed[i] = true; // Mark it as existed

            if (k == n) {
                // Print the permutation
                for (int j = 1; j <= n; j++)
                    cout << x[j] << " ";
                cout << endl;
            } else {
                // Recursively generate the next element in the permutation
                Try(k + 1, n);
            }

            // Backtrack: unchoose integer i and mark it as not existed
            existed[i] = false;
        }
    }
}

int main(){
    int n;
    cin >> n;
    Try(1, n);
}