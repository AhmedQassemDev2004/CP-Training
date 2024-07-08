#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n), b(n);
  read_arr(a, n);
  read_arr(b, n);

  int l = 0, r = 2*1e9+7;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    int _k = k;

    for (int i = 0; i < n; i++) {
      if (b[i] < mid * a[i])
        _k -= (a[i] * mid) - b[i];
    }

    if (_k >= 0) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
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
