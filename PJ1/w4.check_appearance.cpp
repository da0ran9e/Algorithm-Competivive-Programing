#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);
    std::unordered_set<int> seen;

    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
        if (seen.count(A[i]) > 0) {
            std::cout << "1" << std::endl;
        } else {
            seen.insert(A[i]);
            std::cout << "0" << std::endl;
        }
    }

    return 0;
}
