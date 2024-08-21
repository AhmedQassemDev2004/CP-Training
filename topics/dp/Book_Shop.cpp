#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(v) v.begin(), v.end()
#define int long long
#define f first
#define s second

const int mod = 1e9 + 7;

void solve(int tc) {
  int n, x;
  cin >> n >> x;

  vector<int> price(n), pages(n);
  for (int i = 0; i < n; i++)
    cin >> price[i];
  for (int i = 0; i < n; i++)
    cin >> pages[i];

  vector<int> dp(x + 1);

  for (int i = 0; i < n; i++) {
    for (int c = x; c > 0; c--) {
      if (price[i] > c)
        continue;

      dp[c] = max(dp[c], pages[i] + dp[c - price[i]]);
    }
  }

  cout << dp[x];
}

int32_t main() {
  FAST_IO;

  int t = 1;
  // cin >> t;
  while (t--) {
    solve(t);
    cout << endl;
  }
  return 0;
}
