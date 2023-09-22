#include <iostream>
#include <vector>

using namespace std;

void combinations(int n, int k, int start, vector<int> &comb, vector<vector<int>> &result) {
    if (comb.size() == k) {
        result.push_back(comb);
        return;
    }

    for (int i = start; i <= n; ++i) {
        comb.push_back(i);
        combinations(n, k, i+1, comb, result);
        comb.pop_back();
    }
}

vector<vector<int>> get_combinations(int n, int k) {
    vector<vector<int>> result;
    vector<int> comb;
    combinations(n, k, 1, comb, result);
    return result;
}

int main() {
    int n, k;
    cin >> k >> n;

    vector<vector<int>> combs = get_combinations(n, k);
    for (const auto &comb : combs) {
        for (const auto &num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
