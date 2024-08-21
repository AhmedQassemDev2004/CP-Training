#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(v) v.begin(), v.end()
#define int long long

const int mod = 1e9 + 7;

void solve(int tc) {
  int n, sum;
  cin >> n >> sum;

  vector<int> a(n);
  for (auto& it : a)
    cin >> it;

  vector<int> dp(sum + 1, 0);
  dp[0] = 1;
  for (auto it : a) {
    for (int i = 1; i <= sum; i++) {
      if (i - it >= 0) {
        dp[i] += dp[i - it];
        dp[i] -= (dp[i] >= mod ? mod : 0);
      }
    }
  }

  cout << dp[sum] << '\n';
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
