#include <iostream>
#include <stack>
#include <string>

int main() {
  std::stack<int> stack;
  std::string command;
  int value;

  while (std::cin >> command && command != "#") {
    if (command == "PUSH") {
      std::cin >> value;
      stack.push(value);
    } else if (command == "POP") {
      if (stack.empty()) {
        std::cout << "NULL" << std::endl;
      } else {
        std::cout << stack.top() << std::endl;
        stack.pop();
      }
    }
  }

  return 0;
}
