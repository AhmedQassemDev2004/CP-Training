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

#define TESTS true

auto solve(int tc) {
  string s;
  cin >> s;
  int n = s.length();
  int l = 0, r = 0;
  unordered_map<char, int> mp;
  int _min = INT_MAX;
  while (l < n) {
    while (r < n && !(mp['1'] && mp['2'] && mp['3'])) {
      mp[s[r++]]++;
    }

    if (mp['1'] && mp['2'] && mp['3'])
      _min = min(_min, r - l);

    mp[s[l++]]--;
  }

  if (_min == INT_MAX)
    cout << 0;
  else
    cout << _min;
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    solve(tc + 1);
    cout << endl;
  }
#else
  solve(1);
#endif

  return 0;
}