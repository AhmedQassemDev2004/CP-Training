#include <bits/stdc++.h>
#include <climits>
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

  vector<int> h(n);
  read_arr(h, n);

  vector<int> prefix(n + 1);

  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + h[i];
  }

  int min_sum = LONG_MAX, ans = 0;

  for (int i = 0; i <= n - k; i++) {
    int res = prefix[i + k] - prefix[i];

    if (res < min_sum) {
      min_sum = res;
      ans = i;
    }
  }

  cout << ans + 1;
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
