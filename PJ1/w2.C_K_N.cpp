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
 /*
 Example: 
    3 5

    k =    n!
    n   k!(n-k)!

    C(3, 5) => C(2, 5)

    Initialize numerator and denominator:
                [a]     4  5  
                [b]     1  2  

    Calculate the greatest common divisor (GCD) between [a] and [b]
        i=0; j=0: break;
        i=0, i=1:
            [a]     4  5  
                   ~^~
            [b]     1  2  
                      ~^~
            gcd = 2
            [a]     2  5  
                   ~^~
            [b]     1  1 
                      ~^~
        i=1, j=0: break;
        i=1, j=1: break;
    
    result = 2*5 = 10;
 */