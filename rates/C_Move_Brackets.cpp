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

  string s;
  cin >> s;

  vector<pii> remove;
  int last = 0;
  for (int i = 0; i < n; i++) {

    stack<char> st;
    int j;
    for (j = i; j < n; j++) {
      int c = s[j];
      if (c == ')' && j == i) {
        break;
      }

      if (c == '(') {
        st.push(c);
      } else if (c == ')') {
        if (st.empty())
          break;
        st.pop();
      }

      if (st.empty() && j != i) {
        remove.push_back({i, j});
      }
    }
  }

  for (pii& p : remove) {
    for (int i = p.f; i <= p.s; i++) {
      s[i] = '-';
    }
  }

  int cnt = 0;
  for (char c : s) {
    if (c != '-')
      cnt++;
  }

  cout << cnt / 2 << '\n';
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