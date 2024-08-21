#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(), v.end()
#define int long long
// clang-format on

int solve_rec(vector<vector<int>>& a, int i = 0, int j = 0, int sum = 0) {
  int n = a.size(), m = a[0].size();

  if (i >= n || j >= m) {
    return -1e5;
  }

  if (i == n - 1 && j == m - 1) {
    return sum + a[i][j];
  }

  int right = solve_rec(a, i, j + 1, sum + a[i][j]);
  int down = solve_rec(a, i + 1, j, sum + a[i][j]);

  return max(right, down);
}

int solve_dp(vector<vector<int>>& a) {
  int n = a.size(), m = a[0].size();

  vector<vector<int>> dp = a;

  for (int i = 1; i < n; i++) {
    dp[i][0] += dp[i - 1][0];
  }

  for (int i = 1; i < n; i++) {
    dp[0][i] += dp[0][i - 1];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
    }
  }

  return dp[n - 1][m - 1];
}

void solve(int tc) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  cout << solve_dp(a);
}

int32_t main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(t);
  }
  return 0;
}
