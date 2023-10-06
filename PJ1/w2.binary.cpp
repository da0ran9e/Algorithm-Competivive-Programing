#include <bits/stdc++.h>
using namespace std;

#define NMAX 100

int x[NMAX];

void Try(int k, int n){
    for(int i = 0; i <= 1; i++){
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
//example: n = 3

// |Try the first bit with '0'
// |    |While k != n then continue try the second bit with '0'
// |    |    |While k != n then continue try 
// |    |    |  the thirt bit with '0' then check:
// |    |    |  If k == n then print the solution | and try '1'| then print solution ...
// |    |    |                                    |            |
// |    |    |                                    |            |
// |    |    |                                    |            |
// |    |    |0   0   0 <<~~~~~~~~~~~~~~~~~~~~~~~~             |
// |    |     ~~~~~~~~^~                                       |
// |    |     ~~~~~~~~v~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// |    |     0   0   1 
// |     ~~~~~~~~~^~~~~~
// |          0   1   0 
// |          0   1   1 
//  ~~~~~~~~~~^~~~~~~~~~

//            1   0   0 
//            1   0   1 
//            1   1   0
//            1   1   1 