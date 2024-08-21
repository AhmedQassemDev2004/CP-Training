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

  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += h[i];
  }

  int min_sum = sum;
  int min_index = 0;

  for (int i = k; i < n; i++) {
    sum += h[i] - h[i - k];

    if (sum < min_sum) {
      min_sum = sum;
      min_index = i - k + 1;
    }
  }

  cout << min_index + 1 << "\n";

  return 0;
}
