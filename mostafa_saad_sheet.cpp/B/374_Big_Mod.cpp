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

int b, p, m;

int solve(int b, int p, int m) {
  if (p == 0)
    return 1;

  int half = solve(b, p / 2, m);
  half *= half;

  if (p % 2 != 0)
    half = (half * b) % m;

  return half % m;
}

signed main() {
  FAST_IO

  while (cin >> b >> p >> m) {
    cout << solve(b, p, m) << '\n';
  }
  return 0;
}