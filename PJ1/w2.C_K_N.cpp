#include <bits/stdc++.h>
using namespace std;

#define min(a,b) a<b?a:b
#define MAX 100
#define MOD 1000000007

int M[MAX][MAX];// M[k][n] store the value of C(k,n)

int C(int k,int n){
    k = min(k, n-k); // eg: 3C5 = 2C5
    int a[k], b[k]; 
    int D;
    long long int result = 1;

    for (int i = 0; i < k; i++) {
        a[i] = n-k+1+i; // n! / (n-k)! = n(n-1)...(n-k+1)
        b[i] = i+1; // k!
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (b[i] == 1) break;
            D = std::__gcd(b[i], a[j]); //greatest common divisor 
            a[j] = a[j]/D;
            b[i] = b[i]/D;
        }
    }

    for (int i=0; i<k; i++){
        result = (result*a[i])%MOD;
    }

    return result;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << C(a, b);
}
