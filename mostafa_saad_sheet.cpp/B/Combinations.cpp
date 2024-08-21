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

int solve(int n, int m) {
  if (m > n - m)
    m = n - m;

  int res = 1;
  for (int i = 1; i <= m; i++) {
    res *= n - (m - i);
    res /= i;
  }

  return res;
}

signed main() {
  FAST_IO

  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;
    cout << n << " things taken " << m << " at a time is " << solve(n, m) << " exactly.\n";
  }
  return 0;
}