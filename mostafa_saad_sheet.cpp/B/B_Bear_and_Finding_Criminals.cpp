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

#define TESTS 0

auto solve(int tc) {
  int n, k;
  cin >> n >> k;

  int a[n + 1];
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  int res = a[k];
  for (int d = 1; d < n; d++) {
    bool first = false, second = false, first_exists = false, second_exists = false;

    first_exists = k - d >= 1;
    if (first_exists)
      first = a[k - d];

    second_exists = k + d <= n;
    if (second_exists)
      second = a[k + d];

    if (first_exists && second_exists) {
      res += (first && second) * 2;
    } else if (first_exists || second_exists) {
      res += first || second;
    }
  }

  cout << res << '\n';
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