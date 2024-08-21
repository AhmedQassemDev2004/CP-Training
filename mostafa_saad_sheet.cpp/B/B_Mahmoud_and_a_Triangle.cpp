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

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  for (int i = 1; i < n - 1; i++) {
    int x = a[i], y = a[i - 1], z = a[i + 1];
    if (x + y > z && x + z > y && z + y > x) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}