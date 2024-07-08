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
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve(int tc) {
  int n;
  cin >> n;

  vector<pii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].f >> a[i].s;
  }

  sort(all(a));

  vector<pii> res;
  for (auto p : a) {
    if (res.empty()) {
      res.push_back(p);
    } else if (res.back().f <= p.f && res.back().s >= p.f) {
      pii s = {res.back().f,
               max(res.back().s, p.s)};
      res.pop_back();
      res.push_back(s);
    } else {
      res.push_back(p);
    }
  }

  for (auto [x, y] : res) {
    cout << x << ' ' << y << '\n';
  }

  // There's another solution using partial sum
  // but this is easier
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