#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define tests false

auto solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n), t(n);
  read_arr(a, n);
  read_arr(t, n);

  vector<int> arr(n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] == 1) {
      ans += a[i];
    } else {
      arr[i] = a[i];
    }
  }

  if (k == 1) {
    cout << ans << '\n';
    return;
  }

  vector<int> prefix(arr.size());
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + arr[i];
  }

  int _max = 0;
  if (k == 1) {
    _max = *max_element(all(arr));
  } else {
    for (int i = k - 1; i < n; i++) {
      _max = max(_max, prefix[i] - prefix[i - k]);
    }
  }

  cout << (ans + _max) << '\n';
}

signed main() {
  fast_io

#if tests
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
