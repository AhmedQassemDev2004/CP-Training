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

auto solve(int tc) {
  int k, n, m;
  cin >> k >> n >> m;

  int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int i = 0, j = 0;
  vector<int> res;
  while (i < n || j < m) {
    if (i < n && a[i] == 0) {
      res.push_back(a[i++]);
      k++;
    } else if (j < m && b[j] == 0) {
      res.push_back(b[j++]);
      k++;
    } else if (i < n && a[i] <= k) {
      res.push_back(a[i++]);
    } else if (j < m && b[j] <= k) {
      res.push_back(b[j++]);
    } else {
      cout << -1 << endl;
      return;
    }
  }

  for (auto& it : res)
    cout << it << ' ';
  cout << '\n';
}

signed main() {
  FAST_IO

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}