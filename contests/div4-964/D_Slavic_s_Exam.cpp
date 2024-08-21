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

bool is_subsequence(const string& a, const string& b) {
  int i = 0, j = 0;
  while (i < a.length() && j < b.length()) {
    if (a[i] == b[j]) {
      j++;
    }
    i++;
  }
  return j == b.length();
}

auto solve(int tc) {
  string s, t;
  cin >> s >> t;

  int n = s.length(), m = t.length();
  bool possible = false;

  for (int start = 0; start <= n - m; start++) {
    string temp = s;
    bool valid = true;

    for (int i = 0; i < m; i++) {
      if (temp[start + i] != '?' && temp[start + i] != t[i]) {
        valid = false;
        break;
      }
      temp[start + i] = t[i];
    }

    if (!valid)
      continue;

    for (char& c : temp) {
      if (c == '?') {
        c = 'a';
      }
    }

    if (is_subsequence(temp, t)) {
      possible = true;
      cout << "YES\n"
           << temp << '\n';
      break;
    }
  }

  if (!possible) {
    cout << "NO\n";
  }
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
