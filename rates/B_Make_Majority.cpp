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

  vector<int> res;
  vector<int> zeros;
  for (char c : s) {
    if (c == '0') {
      zeros.push_back(0);
    } else if (c == '1' && zeros.size()) {
      res.push_back(0);
      res.push_back(1);
      zeros.clear();
    } else {
      res.push_back(1);
    }
  }

  if (zeros.size())
    res.push_back(0);

  int zero = count(all(res), 0);
  int one = count(all(res), 1);

  if (zero >= one) {
    cout << "No";
  } else {
    cout << "Yes";
  }
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