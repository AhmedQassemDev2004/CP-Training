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

auto solve(int tc) {
  string s;
  cin >> s;

  bool all_same = true;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[0]) {
      all_same = false;
      break;
    }
  }

  if (all_same) {
    cout << "NO\n";
    return;
  }

  string r = s;
  for (size_t i = 1; i < r.size(); ++i) {
    if (r[i] != r[0]) {
      swap(r[0], r[i]);
      cout << "YES" << endl;
      cout << r << endl;
      return;
    }
  }

  cout << "NO\n";
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