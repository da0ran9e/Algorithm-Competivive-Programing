#include <iostream>
#include <stack>
using namespace std;

bool is_valid(string s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' && !stk.empty() && stk.top() == '(') {
            stk.pop();
        } else if (c == ']' && !stk.empty() && stk.top() == '[') {
            stk.pop();
        } else if (c == '}' && !stk.empty() && stk.top() == '{') {
            stk.pop();
        } else {
            return false;
        }
    }
    return stk.empty();
}

int main() {
    string s;
    cin >> s;
    if (is_valid(s)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
