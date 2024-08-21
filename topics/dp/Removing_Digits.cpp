#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(v) v.begin(), v.end()
#define int long long

void solve(int tc) {
  int n;
  cin >> n;

  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    int temp = i;
    while (temp > 0) {
      int d = temp % 10;
      dp[i] = min(dp[i], dp[i - d] + 1);
      temp /= 10;
    }
  }

  cout << dp[n] << '\n';
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
