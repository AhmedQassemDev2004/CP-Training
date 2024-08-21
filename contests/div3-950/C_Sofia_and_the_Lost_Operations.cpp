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

#define TESTS 1

auto solve(int tc) {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int m;
  cin >> m;

  vector<int> d(m);
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
}

signed main() {
  FAST_IO

  int t = 1;
#if TESTS
  cin >> t;
#endif
  for (int tc = 0; tc < t; tc++) {
    solve(tc + 1);
  }

  return 0;
}