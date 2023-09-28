// #include <cmath>
// #include <iostream>

// const int maxn = 1000006;

// int n, m, a[maxn], M[maxn][21];

// int main() {
//   std::cin >> n;
//   for (int i = 1; i <= n; i++) {
//     std::cin >> a[i];
//     M[i][0] = a[i];
//   }

//   int j = 0;
//   while ((1 << j) <= n) {
//     for (int i = 1; i + (1 << j) - 1 <= n; i++) {
//       M[i][j + 1] = std::min(M[i][j], M[i + (1 << j)][j]);
//     }
//     j++;
//   }

//   std::cin >> m;
//   int sum = 0;
//   for (int t = 1; t <= m; t++) {
//     int i, j;
//     std::cin >> i >> j;
//     i++;
//     j++;
//     int k = log2(j - i + 1);
//     int u = i;
//     int v = j - (1 << k) + 1;
//     sum += std::min(M[u][k], M[v][k]);
//   }
//   std::cout << sum;

//   return 0;
// }

#include <cmath>
#include <iostream>
#include <vector>

const int maxn = 1000006;

int n, m, a[maxn];
std::vector<int> st;

void build(int p, int l, int r) {
  if (l == r) {
    st[p] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(2 * p, l, mid);
  build(2 * p + 1, mid + 1, r);
  st[p] = std::min(st[2 * p], st[2 * p + 1]);
}

int query(int p, int l, int r, int i, int j) {
  if (i <= l && r <= j) return st[p];
  int mid = (l + r) / 2;
  if (j <= mid) return query(2 * p, l, mid, i, j);
  if (mid < i) return query(2 * p + 1, mid + 1, r, i, j);
  return std::min(query(2 * p, l, mid, i, mid), query(2 * p + 1, mid + 1, r, mid + 1, j));
}

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  st.resize(4 * n);
  build(1, 1, n);

  std::cin >> m;
  int sum = 0;
  for (int t = 1; t <= m; t++) {
    int i, j;
    std::cin >> i >> j;
    i++;
    j++;
    sum += query(1, 1, n, i, j);
  }
  std::cout << sum;

  return 0;
}
