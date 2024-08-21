#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS false

int max_lcm(int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  if (n == 3)
    return 6;

  int max_lcm = 0;

  max_lcm = max(max_lcm, lcm(lcm(n, n - 1), n - 2));
  max_lcm = max(max_lcm, lcm(lcm(n, n - 1), n - 3));
  max_lcm = max(max_lcm, lcm(lcm(n, n - 2), n - 3));
  max_lcm = max(max_lcm, lcm(lcm(n - 1, n - 2), n - 3));

  return max_lcm;
}

auto solve(int tc) {
  int n;
  cin >> n;

  cout << max_lcm(n);
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
