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
  int n;
  cin >> n;

  string s;
  cin >> s;

  map<char, int> mp;
  for (char c : s) {
    mp[c]++;
  }

  int res = 0;
  for (auto [a, b] : mp) {
    if (a == '?')
      continue;
    if (b >= n)
      res += n;
    else
      res += b;
  }

  cout << res;
}

signed main() {
  FAST_IO

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
    cout << '\n';
  }
  return 0;
}