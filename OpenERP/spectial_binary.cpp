#include <iostream>
using namespace std;

void generate(int n, string s) {
    if (n == 0) {
        cout << s << endl;
        return;
    }
    if (s[s.length() - 1] != '1') {
        generate(n - 1, s + "0");
        generate(n - 1, s + "1");
    } else {
        generate(n - 1, s + "0");
    }
}

int main() {
    int n;
    cin >> n;
    generate(n, "");
    return 0;
}
