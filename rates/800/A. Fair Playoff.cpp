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
#define max_heap(type) std::priority_queue<type>
#define min_heap(type) std::priority_queue<type, std::vector<type>, std::greater<type>>
#define f first
#define s second
// clang-format on

#define TESTS true

auto solve(int tc) {

  vector<int> arr(4);
  read_arr(arr, 4);

  vector<int> sorted(all(arr));
  sort(all(sorted));
  int max1 = sorted[3], max2 = sorted[2];

  if ((max(arr[0], arr[1]) == max1 && min(arr[0], arr[1]) == max2) ||
      (max(arr[2], arr[3]) == max1 && min(arr[2], arr[3]) == max2)) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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
