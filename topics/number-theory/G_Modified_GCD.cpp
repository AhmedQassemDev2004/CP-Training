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

#define TESTS false

set<int> divisors(int n) {
  set<int> res;

  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.insert(i);
      res.insert(n / i);
    }
  }

  return res;
}

auto solve(int tc) {
  int a, b;
  cin >> a >> b;

  int q;
  cin >> q;

  int _gcd = gcd(a, b);

  set<int> divs = divisors(_gcd);

  while (q--) {
    int l, h;
    cin >> l >> h;

    if (l > _gcd) {
      cout << -1 << '\n';
    } else if (l == _gcd || h == _gcd) {
      cout << _gcd << '\n';
    } else {
      auto it = divs.upper_bound(h);
      if (it == divs.begin() || *(--it) < l) {
        cout << -1 << '\n';
      } else {
        cout << *it << '\n';
      }
    }
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