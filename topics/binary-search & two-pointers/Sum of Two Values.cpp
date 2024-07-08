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
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1;
  }

  sort(all(arr));

  int left = 0, right = n - 1;
  while (left < right) {
    int sum = arr[left].first + arr[right].first;
    int first = min(arr[left].second, arr[right].second),
        second = max(arr[left].second, arr[right].second);

    if (sum == k) {
      cout << first << ' ' << second << '\n';
      return;
    }

    if (sum < k) {
      left++;
    } else {
      right--;
    }
  }

  cout << "IMPOSSIBLE\n";
}

signed main() {
  FAST_IO;

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
