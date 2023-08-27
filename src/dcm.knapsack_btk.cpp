#include <iostream>
#include<climits>
using namespace std;

int ck, w1, fopt, fk, n;
int x[100], xopt[100], w[100], p[100];

int backtrack(int k){
    int t = ck/w[k];
    for (int i = 0; i <= t; i++){
            x[k] = i;
            fk += p[k] * x[k];
            ck -= w[k] * x[k];
            if (k == n) {
                if (fk > fopt) {
                    fopt = fk;
                    for (int j = 1; j <= n; j++)
                        xopt[j] = x[j];
                }
            } else backtrack(k+1);
           fk -= p[k] * x[k];
           ck += w[k] * x[k];
    }
}

int main(int argc, char *argv[])
{
	
	cin >> n;
	cin >> w1;
	for (int i = 1; i <= n; i++)
	    cin >> p[i];
	for (int i = 1; i <= n; i++)
	    cin >> w[i];

	
	    
	ck = w1;
	fk = 0;
	fopt = INT_MIN;
	
	backtrack(1);
	cout << fopt << "\n";
	for (int j = 1; j <= n; j++)
        cout << j << ": " << xopt[j] << "\n";

}