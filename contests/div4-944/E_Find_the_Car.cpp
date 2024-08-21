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
  int n, k, q;
  cin >> n >> k >> q;

  int a[k + 1] = {}, b[k + 1] = {};

  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= k; i++) {
    cin >> b[i];
  }

  while (q--) {
    int d;
    cin >> d;

    if (d == n) {
      cout << b[k] << ' ';
      continue;
    }

    int i = upper_bound(a, a + k + 1, d) - a - 1;
    d -= a[i];

    int dis = a[i + 1] - a[i];
    int time = b[i + 1] - b[i];
    cout << b[i] + d * time / dis << ' ';
  }
  cout << '\n';
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