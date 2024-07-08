#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
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

#define TESTS true

auto solve(int tc) {
  int n, k;
  cin >> n >> k;

  int l = 1, r = 2e9;
  int ans = 0;

  while (l <= r) {
    int mid = (l + r) / 2;
    int kth = mid - mid / n;

    if (kth == k) {
      ans = mid;
      break;
    }

    if (kth < k) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  if (ans % n == 0)
    ans--;
  cout << ans << '\n';
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve(i + 1);
  }
#else
  solve(1);
#endif

  return 0;
}
