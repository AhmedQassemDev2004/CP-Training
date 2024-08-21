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

#define TESTS 0

auto solve(int tc) {
  int n;
  cin >> n;

  string res = "ROYGBIV";

  map<char, int> first, last;
  for (int i = 0; i < 7; i++) {
    first[res[i]] = i;
    last[res[i]] = i;
  }

  for (int i = 7; i < n; i++) {
    for (int j = 0; j < 7; j++) {
      char c = res[j];

      bool ok = true;

      if (i - last[c] + 1 <= 4) {
        ok = false;
      }

      if ((n - i) + (first[c] + 1) <= 4) {
        ok = false;
      }

      if (ok) {
        last[c] = i;
        res.push_back(c);
        break;
      }
    }
  }

  cout << res;
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