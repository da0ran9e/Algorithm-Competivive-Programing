#include <iostream> 
#include <string>
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    int n; 
    std::string oldpassword; 
    std::cin >> n >> oldpassword; 
    int uppercase = 0;
    int lowercase = 0; 
    int digit = 0; 
    int special = 0; 
    for (int i = 0; i < n; i++) {
      if ('0' <= oldpassword[i] && oldpassword[i] <= '9') {
        digit++; 
      }
      else if ('a' <= oldpassword[i] && oldpassword[i] <= 'z') {
        lowercase++; 
      }
      else if ('A' <= oldpassword[i] && oldpassword[i] <= 'Z') {
        uppercase++; 
      }
      else if (oldpassword[i] == '@' || oldpassword[i] == '#' || oldpassword[i] == '&' || oldpassword[i] == '*') {
        special++;  
      }
    }
    if (digit == 0) {
      oldpassword += '0';
    }
    if (lowercase == 0) {
      oldpassword += 'a';
    }
    if (uppercase == 0) {
      oldpassword += 'A';
    }
    if (special == 0) {
      oldpassword += '@';
    }
    while ((int) oldpassword.size() < 7) {
      oldpassword += 'a'; 
    }
    std::cout << oldpassword << std::endl; 
  }
  return 0; 
}