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

void solve(int tc) {
  int n, s, m;
  cin >> n >> s >> m;

  vector<pair<int, int>> tasks(n);
  for (int i = 0; i < n; i++) {
    cin >> tasks[i].first >> tasks[i].second;
  }

  sort(tasks.begin(), tasks.end());

  if (tasks[0].first >= s) {
    cout << "YES\n";
    return;
  }

  for (int i = 1; i < n; i++) {
    if (tasks[i].first - tasks[i - 1].second >= s) {
      cout << "YES\n";
      return;
    }
  }

  if (m - tasks[n - 1].second >= s) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
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