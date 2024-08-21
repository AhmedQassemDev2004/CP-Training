#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second

signed main() {
  FAST_IO

  int n, m;
  char c;
  cin >> n >> m >> c;

  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  set<char> res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == c) {
        if (i + 1 < n)
          res.insert(a[i + 1][j]);
        if (i - 1 >= 0)
          res.insert(a[i - 1][j]);
        if (j + 1 < m)
          res.insert(a[i][j + 1]);
        if (j - 1 >= 0)
          res.insert(a[i][j - 1]);
      }
    }
  }

  res.erase('.');
  res.erase(c);

  cout << res.size() << '\n';

  return 0;
}