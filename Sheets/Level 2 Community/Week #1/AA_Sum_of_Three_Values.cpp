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
  int n, k;
  cin >> n >> k;

  // 2 7 5 1
  // 1 2 5 7
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1;
  }

  sort(all(arr));

  for (int i = 0; i < n; i++) {
    int l = i + 1, r = n - 1;
    while (l < r) {
      int sum = arr[i].f + arr[l].f + arr[r].f;
      if (sum == k) {
        cout << arr[i].s << ' ' << arr[l].s << ' ' << arr[r].s;
        return;
      }

      if (sum < k)
        ++l;
      else
        --r;
    }
  }

  cout << "IMPOSSIBLE";
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