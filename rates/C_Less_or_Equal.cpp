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

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(all(a));

  if (k == 0) {
    if (a[0] <= 1) {
      cout << -1;
    } else {
      cout << a[0] - 1 << endl;
    }

    return 0;
  }

  if (k == n) {
    cout << a[n - 1];
  } else if (a[k - 1] < a[k]) {
    cout << a[k - 1];
  } else {
    cout << -1;
  }
  return 0;
}