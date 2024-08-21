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

#define TESTS 1

auto solve(int tc) {
  map<char, int> occur = {
      {'A', 0},
      {'B', 0},
      {'C', 0},
      {'D', 0},
      {'E', 0},
      {'F', 0},
      {'G', 0},
  };

  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  for (char c : s) {
    occur[c]++;
  }

  int count = 0;
  for (auto [a, b] : occur) {
    if (b < m) {
      count += m - b;
    }
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