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

auto solve(int tc) {
  int n, f, k;
  cin >> n >> f >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int fav = a[f - 1];
  int fav_count = count(all(a), fav);

  sort(rall(a));

  int fav_removed = 0;
  for (int i = 0; i < k; i++) {
    fav_removed += a[i] == fav;
  }

  if (fav_removed == fav_count) {
    cout << "YES\n";
  } else if (fav_removed == 0) {
    cout << "NO\n";
  } else {
    cout << "MAYBE\n";
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