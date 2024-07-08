#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define ln '\n'
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  read_arr(a, n);
  read_arr(b, m);

  sort(all(a));
  sort(all(b));

  int ans = 0;
  for (auto x : a) {
    int p = lower_bound(all(b), x) - b.begin();

    if (p == 0) {
      ans = max(ans, abs(b[0] - x));
    } else if (p == m) {
      ans = max(ans, abs(b[m - 1] - x));
    } else {
      int y = min(abs(b[p] - x), abs(b[p - 1] - x));
      ans = max(ans, y);
    }
  }

  cout << ans;
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
#else
  solve();
#endif

  return 0;
}
