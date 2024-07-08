#include <bits/stdc++.h>
#include <climits>
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

auto solve() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  vector<int> prefix(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + (s[i - 1] == 'B');
  }

  int ans = LONG_LONG_MAX;
  for (int i = k - 1; i < n; i++) {
    int number_of_b = prefix[i + 1] - prefix[i - k + 1];
    ans = min(ans, k - number_of_b);
  }

  cout << ans << '\n';
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
