#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        int hash = 0;
        string s;
        cin >> s;

        for (int j=0; j<s.length(); j++) {
            hash = (hash*256 + s[j])%m;
        }
        cout << hash << endl;
    }
    
    return 0;
}
