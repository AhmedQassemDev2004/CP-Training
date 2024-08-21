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
  int n, p;
  cin >> n;

  set<int> st;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    cin >> p;
    if (!st.empty() && st.count(p - 1) == 0 && st.count(p + 1) == 0) {
      flag = false;
    }

    st.insert(p);
  }

  cout << (flag ? "YES\n" : "NO\n");
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