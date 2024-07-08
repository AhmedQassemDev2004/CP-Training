#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(NULL);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
// #define sort(a) sort(all(a))
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

struct user {
  string name;
  int count, pen;
};

bool cmp(user& u1, user& u2) {
  if (u1.count == u2.count) {
    if (u1.pen == u2.pen)
      return u1.name < u2.name;
    return u1.pen < u2.pen;
  }

  return u1.count > u2.count;
}

auto solve(int tc) {
  int n;
  cin >> n;

  vector<user> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].name >> a[i].count >> a[i].pen;

  sort(all(a), cmp);

  for (auto u : a) {
    cout << u.name << ' ' << u.count << ' ' << u.pen << endl;
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