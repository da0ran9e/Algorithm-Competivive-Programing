#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    set<string> words;
    string word;
    while (cin >> word && word != "*") {
        words.insert(word);
    }
    string command;
    while (cin >> command) {
        if (command == "***") {
            break;
        }

        cin >> word;
        if (command == "find") {
            cout << (words.count(word) > 0 ? 1 : 0) << endl;
        } else if (command == "insert") {
            pair<set<string>::iterator, bool> result = words.insert(word);
            cout << (result.second ? 1 : 0) << endl;
        }
    }
    return 0;
}
