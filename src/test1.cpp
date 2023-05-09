#include <bits/stdc++.h>
using namespace std;

int M = 1000000007;
int combination(int n, int k)
{
    k = min(k, n-k);
    int A[k], B[k], i, j;
    iota(A, A+k, n-k+1);  //initializing A starting from n-r+1 to n
    iota(B, B+k, 1);      //initializing B starting from 1 to r

    int g;
    for(i = 0; i < k; i++)
        for(j = 0; j < k; j++)
        {
            if(B[i] == 1) break;
            g = __gcd(B[i], A[j]);
            A[j] /= g;
            B[i] /= g;
        }

    long long res = 1;
    for(i = 0; i < k; i++)
        res = (res * A[i]) % M;
    return res;
}


int main(){
    int k, n;

    cin >> k >> n;
    cout << combination(n, k);
    return 0;
}