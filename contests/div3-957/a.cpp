#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(v) v.begin(), v.end()
#define int long long
#define pii pair<int, int>
#define f first
#define s second

const int mod = 1e9 + 7;

void solve(int tc) {
  vector<int> a(3);
  for (auto& it : a)
    cin >> it;

  int count = 0;
  while (count < 5) {
    auto _min = min_element(all(a));
    (*_min)++;
    count++;
  }

  int res = 1;
  for (auto it : a) {
    res *= it;
  }

  cout << res;
}

int32_t main() {
  FAST_IO;

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  cin >> t;
  while (t--) {
    solve(t);
    cout << endl;
  }
  return 0;
}
