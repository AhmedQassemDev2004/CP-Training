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
  int n;
  cin >> n;

  int c1 = 0, c2 = 0;
  if (n == 1) {
    c1 = 1;
  } else if (n == 2) {
    c2 = 1;
  } else {
    if (n % 3 == 0) {
      c1 = c2 = n / 3;
    } else {
      c1 = n / 3 + 1;
      c2 = n / 3;
      if (c1 + c2 * 2 != n) {
        swap(c1, c2);
      }
    }
  }

  cout << c1 << ' ' << c2 << '\n';
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
