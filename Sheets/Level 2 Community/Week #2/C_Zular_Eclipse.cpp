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
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
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

  vector<int> a(n);
  read_arr(a, n);

  sort(all(a));

  vector<int> prefix(n + 1);
  for (int i = 1; i <= n; i++) {
    prefix[i] = a[i - 1] + prefix[i - 1];
  }

  int q;
  cin >> q;

  while (q--) {
    int k;
    cin >> k;

    int l = 0, r = n - 1;
    int ans_index = -1;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (a[mid] <= k) {
        ans_index = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    if (ans_index == -1) {
      cout << -1 << '\n';
    } else {
      cout << ans_index + 1 << ' ' << prefix[ans_index + 1] << '\n';
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