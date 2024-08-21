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

auto solve() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n, 1);
  for (int i = y - 2; i >= 0; i--) {
    a[i] = -a[i + 1];
  }

  for (int i = x; i < n; i++) {
    a[i] = -a[i - 1];
  }

  for (auto& it : a)
    cout << it << ' ';
  cout << endl;
}

signed main() {
  FAST_IO

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}