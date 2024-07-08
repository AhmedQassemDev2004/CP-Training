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
  int n, t;
  cin >> n >> t;

  vector<int> books(n);
  read_arr(books, n);

  int left = 0, right = 0, curr = 0, ans = 0;
  while (left < n && right < n) {
    while (right < n && curr + books[right] <= t) {
      curr += books[right++];
    }

    ans = max(ans, right - left);
    curr -= books[left];
    left++;
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
