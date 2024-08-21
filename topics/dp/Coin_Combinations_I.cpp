
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(), v.end()
#define int long long
const int mod = 1e9 + 7;
// clang-format on

void solve(int tc) {
  int n, sum;
  cin >> n >> sum;

  vector<int> a(n);
  for (auto& it : a) {
    cin >> it;
  }

  vector<int> dp(sum + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= sum; i++) {
    for (auto it : a) {
      if (i - it >= 0)
        dp[i] += dp[i - it];

      if (dp[i] >= mod)
        dp[i] -= mod;
    }
  }

  cout << dp[sum];
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
