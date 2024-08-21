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
  cin >> n;

  string s = to_string(n);
  if (s.length() < 3) {
    cout << "NO\n";
    return;
  }

  string s1 = s.substr(0, 2);
  if (s1 == "10") {
    string s2 = s.substr(2, s.length());
    int s2_n = stoi(s2);
    if (s2_n >= 2 && s2[0] != '0') {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } else {
    cout << "NO\n";
  }
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