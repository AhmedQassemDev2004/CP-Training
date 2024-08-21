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

bool isBetween(int start, int end, int point) {
  if (start < end) {
    return start < point && point < end;
  } else {
    return start < point || point < end;
  }
}

auto solve(int tc) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, d);

  bool intersect = isBetween(a, b, c) != isBetween(a, b, d) &&
                   isBetween(c, d, a) != isBetween(c, d, b);

  if (intersect) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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