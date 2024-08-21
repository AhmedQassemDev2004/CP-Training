#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second

signed main() {
  FAST_IO

  int n, m, k, t;
  cin >> n >> m >> k >> t;

  vector<pii> w(k);

  for (int p = 0; p < k; p++) {
    cin >> w[p].f >> w[p].s;
  }

  sort(all(w));

  while (t--) {
    int i, j;
    cin >> i >> j;

    pii q = {i, j};

    auto it = lower_bound(all(w), q);
    if (it != w.end() && *it == q) {
      cout << "Waste\n";
    } else {
      int w_count = distance(w.begin(), it);
      int p = ((i - 1) * m + (j - 1) - w_count) % 3;

      if (p == 0)
        cout << "Carrots\n";
      else if (p == 1)
        cout << "Kiwis\n";
      else
        cout << "Grapes\n";
    }
  }

  return 0;
}
