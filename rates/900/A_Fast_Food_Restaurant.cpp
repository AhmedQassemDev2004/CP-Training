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
// #define sort(a) sort(all(a))
#define read_arr(arr) for(auto &it: arr) cin>>it;
#define print_arr(arr) for(auto &it: arr) {cout << it;cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS true

auto solve(int tc) {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];

  sort(all(a), greater<int>());

  int res = 0;

  for (int i = 0; i < 3; i++) {
    if (a[i] > 0) {
      res++;
      --a[i];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      if (a[i] > 0 && a[j] > 0) {
        res++;
        a[i]--, a[j]--;
      }
    }
  }

  if (a[0] && a[1] && a[2]) {
    res++;
    a[0]--, a[1]--, a[2]--;
  }

  cout << res << endl;
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
#ifndef ONLINE_JUDGE
  cerr << "Time: " << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
#endif
#endif

  return 0;
}