#include <algorithm>
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
  int n, t;
  cin >> n >> t;

  vector<int> k(n);
  read_arr(k, n);

  int ans = 0;
  int l = 1, r = 1ll * *min_element(all(k)) * t;

  auto good = [&](int mid) {
    int res = 0;
    for (auto x : k) {
      res += mid / x;
      if (res >= t)
        break;
    }

    if (res >= t) {
      ans = mid;
      return true;
    }

    return false;
  };

  while (l <= r) {
    int mid = (l + r) / 2;

    if (good(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
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
