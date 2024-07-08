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
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  read_arr(a);

  int l = 0, r = 0, ans = -1, ans_l = 0, ans_r = 0;
  unordered_map<int, int> occur;
  for (; r < n; r++) {
    occur[a[r]]++;
    while (occur.size() > k) {
      occur[a[l]]--;
      if (occur[a[l]] == 0)
        occur.erase(a[l]);
      l++;
    }
    if (r - l + 1 > ans) {
      ans = r - l + 1;
      ans_l = l;
      ans_r = r;
    }
  }

  cout << ans_l + 1 << ' ' << ans_r + 1;
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