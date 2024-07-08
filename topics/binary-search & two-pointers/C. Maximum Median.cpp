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
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define Uc
// clang-format on

#define TESTS false

int last_true(int left, int right, function<bool(int)> func) {
  int ans = -1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (func(mid)) {
      left = mid + 1;
      ans = mid;
    } else {
      right = mid - 1;
    }
  }

  return ans;
}

auto solve() {
  int n, k;
  cin >> n >> k;

  int arr[n];
  read_arr(arr, n);

  sort(arr, arr + n);

  int res = last_true(1, 2e9, [&](int x) {
    int ops = 0;
    for (int i = (n - 1) / 2; i < n; i++)
      ops += max((int)0, x - arr[i]);

    return ops <= k;
  });

  cout << res;
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
