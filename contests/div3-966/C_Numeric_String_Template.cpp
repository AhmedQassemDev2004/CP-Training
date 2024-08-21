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

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int m;
  cin >> m;

  while (m--) {
    string s;
    cin >> s;

    if (s.length() != n) {
      cout << "NO\n";
      continue;
    }

    map<int, char> int_to_char;
    map<char, int> char_to_int;
    bool flag = true;

    for (int i = 0; i < n; i++) {
      if (int_to_char.count(a[i]) > 0) {
        if (int_to_char[a[i]] != s[i]) {
          flag = false;
          break;
        }
      } else {
        int_to_char[a[i]] = s[i];
      }

      if (char_to_int.count(s[i]) > 0) {
        if (char_to_int[s[i]] != a[i]) {
          flag = false;
          break;
        }
      } else {
        char_to_int[s[i]] = a[i];
      }
    }

    if (flag)
      cout << "YES\n";
    else
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