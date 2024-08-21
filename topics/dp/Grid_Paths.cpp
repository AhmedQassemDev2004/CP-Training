#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(v) v.begin(), v.end()
#define int long long

const int mod = 1e9 + 7;

// very slow solution
int rec(vector<vector<char>> a, int i = 0, int j = 0) {
  int n = a.size();

  if (i >= n || j >= n || a[i][j] == '*') {
    return 0ll;
  }

  if (i == n - 1 && j == n - 1) {
    return 1ll;
  }

  int right = rec(a, i, j + 1);
  int left = rec(a, i + 1, j);

  return (left + right) % mod;
}

void solve(int tc) {
  int n;
  cin >> n;

  vector<vector<char>> a(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));
  if (a[0][0] == '*') {
    cout << 0 << endl;
    return;
  } else {
    dp[0][0] = 1;
  }

  for (int i = 1; i < n; i++) {
    if (a[0][i] == '*')
      break;
    dp[0][i] = 1;
  }

  for (int i = 1; i < n; i++) {
    if (a[i][0] == '*')
      break;
    dp[i][0] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (a[i][j] == '*')
        continue;
      if (a[i - 1][j] != '*')
        dp[i][j] += dp[i - 1][j];
      if (a[i][j - 1] != '*')
        dp[i][j] += dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }

  cout << dp[n - 1][n - 1] << endl;
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
