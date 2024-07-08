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
// clang-format on

#define TESTS false

auto solve() {
  int n, x;
  cin >> n >> x;

  vector<int> arr(n);
  read_arr(arr, n);

  int left = 0, right = 0, sum = 0, ans = 0;
  while (left < n) {
    while (right < n && sum < x) {
      sum += arr[right++];
    }

    if (sum == x)
      ans++;

    sum -= arr[left++];
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
