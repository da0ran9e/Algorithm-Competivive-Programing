#include<bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {
    int n = num1.size(), m = num2.size();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + res[p2];

            res[p1] += sum / 10;
            res[p2] = sum % 10;
        }
    }
    string result = "";
    int i = 0;
    while (i < n + m && res[i] == 0) i++;
    while (i < n + m) result += to_string(res[i++]);
    return result.empty() ? "0" : result;
}

int main()
{
  string a, b;
  cin >> a >> b;
  cout << multiply(a, b);
}
