#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(), v.end()
#define int long long
// clang-format on

void solve(int tc) {
  int n, p;
  cin >> n;

  vector<int> a(n);
  for (auto& it : a)
    cin >> it;

  vector<int> dp(n, 1);
  int ans = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i])
        dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(dp[i], ans);
  }

  cout << ans;
}

int32_t main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(t);
  }
  return 0;
}
