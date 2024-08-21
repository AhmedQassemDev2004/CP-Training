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

void red(int& a, int& b) {
  int g = __gcd(a, b);
  tie(a, b) = make_pair(g, a / g * b);
}

auto solve(int tc) {
  int n;
  cin >> n;

  int a, b;
  cin >> a >> b;
  red(a, b);

  for (int i = 2; i < n; i++) {
    int x;
    cin >> x;
    b = __gcd(b, x);
    red(a, b);
  }

  cout << b << endl;
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
