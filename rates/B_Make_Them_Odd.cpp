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
  int n, p;
  cin >> n;

  set<int> st;
  for (int i = 0; i < n; i++) {
    cin >> p;
    if (p % 2 == 0) {
      st.insert(p);
    }
  }

  int res = 0;
  while (!st.empty()) {
    int x = *st.rbegin();
    st.erase(x);
    if ((x / 2) % 2 == 0)
      st.insert(x / 2);
    res++;
  }

  cout << res << '\n';
}

signed main() {
  FAST_IO

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++)
    solve(i);
  return 0;
}