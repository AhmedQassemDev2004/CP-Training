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

auto solve(int tc) {

  string strs;
  cin >> strs;

  if (strs.length() < 2) {
    cout << 0;
    return;
  }

  int x = 11, count = 0;

  while (x >= 10) {
    x = 0;
    for (int i = 0; i < strs.length(); i++) {
      x += (strs[i] - '0');
    }

    strs = to_string(x);
    count++;
  }

  cout << count << '\n';
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