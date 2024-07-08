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
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve(int tc) {
  int n, k;
  cin >> n >> k;

  int arr[n];
  read_arr(arr, n);

  ordered_set<pair<int, int>> window;

  for (int i = 0; i < k; i++)
    window.insert({arr[i], i});

  cout << window.find_by_order((k - 1) / 2)->f << ' ';

  for (int i = 1; i < n - k + 1; i++) {
    window.erase({arr[i - 1], i - 1});
    window.insert({arr[i + k - 1], i + k - 1});

    cout << window.find_by_order((k - 1) / 2)->f << ' ';
  }
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve(i + 1);
  }
#else
  solve(1);
#endif

  return 0;
}
