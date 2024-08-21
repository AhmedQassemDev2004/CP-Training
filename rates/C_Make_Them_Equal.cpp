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
  int n;
  char c;
  cin >> n >> c;

  string s;
  cin >> s;

  bool same = true;
  for (char& c1 : s) {
    if (c1 != c) {
      same = false;
      break;
    }
  }

  if (same) {
    cout << 0 << '\n';
    return;
  }

  for (int i = n / 2; i < n; ++i) {
    if (s[i] == c) {
      cout << 1 << endl
           << i + 1 << endl;
      return;
    }
  }

  cout << 2 << endl;
  cout << n << ' ' << n - 1 << endl;
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