#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> words;
    string word, command;

    while (cin >> word && word != "*") {
        words.insert(word);
    }

    while (cin >> command) {
        if (command == "***") {
            break;
        }

        cin >> word;

        if (command == "find") {
            cout << ((words.count(word)>0)?1:0) << endl;
        } else if (command == "insert") {
            pair<set<string>::iterator, bool> result = words.insert(word);
            cout << (result.second?1:0) << endl;
        }
    }
    return 0;
}
