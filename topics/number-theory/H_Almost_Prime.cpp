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

bool is_prime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

auto solve(int tc) {
  int n;
  cin >> n;

  int res = 0;
  for (int i = 1; i <= n; i++) {
    set<int> divs = divisors(i);

    int count = 0;
    for (auto it : divs) {
      if (is_prime(it))
        count++;
    }

    res += (count == 2);
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