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
  int n, q;
  cin >> n >> q;

  vector<int> t(n);
  read_arr(t);

  sort(all(t));
  while (q--) {
    int k;
    cin >> k;

    auto it = lower_bound(all(t), k);
    if (*it == k) {
      cout << *it << '\n';
    } else {
      // 1 1 1 1 1 1

      if (it == t.begin()) {
        cout << *it << '\n';
        continue;
      } else if (it == t.end()) {
        --it;
        cout << *it << '\n';
        continue;
      }

      int temp = *it;
      int diff1 = temp - k;
      int diff2 = k - *(--it);

      if (diff2 <= diff1) {
        cout << *it << '\n';
      } else {
        cout << temp << '\n';
      }
    }
  }
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