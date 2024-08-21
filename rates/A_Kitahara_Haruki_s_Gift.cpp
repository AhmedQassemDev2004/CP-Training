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

  int n;
  cin >> n;

  vector<int> a(n);
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c1 += a[i] == 100, c2 += a[i] == 200;
  }

  int total = c1 * 100 + c2 * 200;

  if (total % 200 != 0) {
    cout << "NO";
  } else {
    for (int i = 0; i <= c2; ++i) {
      int rem = (total / 2) - i * 200;
      if (rem >= 0 && rem <= c1 * 100) {
        cout << "YES" << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
  }

  return 0;
}