#include <iostream>
#define mod 1000000007

using namespace std;

long long fast_pow(long long base, long long exponent) {
    long long res = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return res;
}

int main() {
    long long base, exponent;
    cin >> base >> exponent;
    cout << fast_pow(base, exponent) % mod << endl;
    return 0;
}
