#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        int hash = 0;
        int len = s.length();
        
        for (int j=0; j<len; j++) {
            hash = (hash*256 + s[j])%m;
        }
        
        cout << hash << endl;
    }
    
    return 0;
}
