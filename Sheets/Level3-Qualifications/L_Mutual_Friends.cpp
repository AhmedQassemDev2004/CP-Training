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
#define print_arr(arr) for(auto &it: arr) {cout << it;cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve(int tc) {
  int n;
  cin >> n;

  int a, b;
  cin >> a >> b;

  set<int> a_friends, b_friends;

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    if (x == a)
      a_friends.insert(y);
    else if (y == a)
      a_friends.insert(x);
    else if (x == b)
      b_friends.insert(y);
    else if (y == b)
      b_friends.insert(x);
  }

  int cnt = 0;
  for (auto a1 : a_friends) {
    if (b_friends.count(a1))
      cnt++;
  }

  cout << cnt;
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