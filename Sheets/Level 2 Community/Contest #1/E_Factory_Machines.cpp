#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sort(a) sort(all(a))
#define read_arr(arr) for(auto &it: arr) cin>>it;
#define print_arr(arr) for(auto &it: arr) {cout << *it;cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve(int tc) {
  int n, t;
  cin >> n >> t;

  vector<int> k(n);
  read_arr(k);

  auto valid = [&](int mid) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      res += mid / k[i];
      if (res >= t)
        return true;
    }

    return res >= t;
  };

  int l = 0, r = 1e18;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;

    if (valid(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << ans;
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    solve(tc + 1);
  }
#else
  solve(1);
#endif

  return 0;
}