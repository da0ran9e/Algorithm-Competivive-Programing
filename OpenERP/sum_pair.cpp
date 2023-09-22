#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  unordered_map<int, int> map;
  int x, count = 0;
  
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (map.count(m - x))
      count += map[m - x];
    if (map.count(x))
      map[x]++;
    else
      map[x] = 1;
  }
  
  cout << count << endl;
  
  return 0;
}
