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

#define TESTS false

auto solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  read_arr(a, n);

  // 1 5 -6 7 9 -16 0 -2 2

  vector<int> prefix(n + 1);
  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + a[i];
  }

  // 0 1 6 0 7 16 0 0 -2 0

  /* print_arr(prefix, n + 1); */

  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (prefix[i] - prefix[0] == prefix[n] - prefix[i]) {
      ans++;
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
