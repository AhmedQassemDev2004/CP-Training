#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(), v.end()
#define int long long
// clang-format on
int mod = 1e9 + 7;

void solve(int tc) {
  int n;
  cin >> n;

  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int p = 1; p <= 6; p++) {
      if (i - p >= 0) {
        dp[i] += dp[i - p];
        if (dp[i] >= mod)
          dp[i] -= mod;
      }
    }
  }

  cout << dp[n];
}

int32_t main() {
  FAST_IO;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(t);
    cout << endl;
  }
  return 0;
}
