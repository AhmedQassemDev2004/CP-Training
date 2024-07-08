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
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  read_arr(a, n);

  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;

    a[x] -= z, a[y] += z;
  }

  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      flag = false;
      break;
    }
  }

  cout << (flag ? "YES\n" : "NO\n");
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