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

#define TESTS true

auto solve(int tc) {
  int n, q;
  cin >> n >> q;

  string a, b;
  cin >> a >> b;

  int pre_a[n + 1][26] = {0}, pre_b[n + 1][26] = {0};

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) {
      pre_a[i][j] = pre_a[i - 1][j];
      pre_b[i][j] = pre_b[i - 1][j];
    }

    pre_a[i][a[i - 1] - 'a']++;
    pre_b[i][b[i - 1] - 'a']++;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;

    int res = 0;
    for (int i = 0; i < 26; ++i) {
      int fa = pre_a[r + 1][i] - pre_a[l][i];
      int fb = pre_b[r + 1][i] - pre_b[l][i];
      res += abs(fa - fb);
    }

    cout << res / 2 << '\n';
  }
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    solve(tc + 1);
  }
#else
  solve(1);
#endif

  return 0;
}