#include <bits/stdc++.h>
using namespace std;

int main() {
  stack<int> stack;
  string command;
  int value;

  while (cin >> command && command != "#") {
    if (command == "PUSH") {
      cin >> value;
      stack.push(value);
    } else if (command == "POP") {
      if (stack.empty()) {
        cout << "NULL" << endl;
      } else {
        cout << stack.top() << endl;
        stack.pop();
      }
    }
  }

  return 0;
}