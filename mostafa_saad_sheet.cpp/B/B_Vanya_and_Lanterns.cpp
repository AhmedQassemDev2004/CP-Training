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
// #define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second

signed main() {
  FAST_IO

  int n, l;
  cin >> n >> l;

  vector<double> a(n);
  for (auto& it : a)
    cin >> it;

  sort(all(a));

  double r = 0;
  for (int i = 0; i < n - 1; i++) {
    r = max(r, ((double)a[i + 1] - a[i]) / 2.0);
  }

  if (a[n - 1] != l) {
    r = max(r, (double)(l - a[n - 1]));
  }

  if (a[0] != 0) {
    r = max(r, (double)(a[0]));
  }

  cout << setprecision(10) << fixed << r;

  return 0;
}