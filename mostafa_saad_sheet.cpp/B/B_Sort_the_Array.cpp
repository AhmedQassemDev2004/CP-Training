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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int l = 0, r = n - 1;

  while (l < n - 1 && a[l] <= a[l + 1]) {
    l++;
  }

  if (l == n - 1) {
    cout << "yes\n"
         << 1 << " " << 1 << "\n";
    return 0;
  }

  while (r > 0 && a[r] >= a[r - 1]) {
    r--;
  }

  reverse(a.begin() + l, a.begin() + r + 1);

  if (is_sorted(all(a))) {
    cout << "yes\n"
         << l + 1 << " " << r + 1 << "\n";
  } else {
    cout << "no\n";
  }

  return 0;
}
