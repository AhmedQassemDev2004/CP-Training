#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

signed main() {
  FAST_IO

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<int> prefix(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + v[i - 1];
  }

  vector<int> sorted_v = v;
  sort(sorted_v.begin(), sorted_v.end());
  vector<int> sorted_prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    sorted_prefix_sum[i] = sorted_prefix_sum[i - 1] + sorted_v[i - 1];
  }

  int m;
  cin >> m;
  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      cout << prefix[r] - prefix[l - 1] << '\n';
    } else {
      cout << sorted_prefix_sum[r] - sorted_prefix_sum[l - 1] << '\n';
    }
  }

  return 0;
}
