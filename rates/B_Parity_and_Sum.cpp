#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.rend()
#define pii pair<int, int>
#define f first
#define s second
#define print(v) for(auto&it: v)cout << it << ' ';cout<<'\n';
// clang-format on

auto solve(int tc) {
  int n;
  cin >> n;

  int a[n];
  multiset<int> even, odd;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      even.insert(a[i]);
    } else {
      odd.insert(a[i]);
    }
  }

  if (even.size() == 0 || odd.size() == 0) {
    return (void)(cout << 0);
  }

  int res = 0;
  while (!even.empty()) {
    auto max_odd = odd.rbegin();
    auto min_even = even.begin();
    if (*max_odd > *min_even) {
      odd.insert(*max_odd + *min_even);
      even.erase(min_even);
    } else {
      auto min_odd = odd.begin();
      auto max_even = even.rbegin();
      odd.insert(*min_odd + *max_even);
      odd.erase(min_odd);
    }

    res++;
  }

  cout << res;
}

signed main() {
  FAST_IO

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
    cout << '\n';
  }
  return 0;
}
