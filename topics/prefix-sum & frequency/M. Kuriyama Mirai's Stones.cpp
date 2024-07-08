#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve() {
  int n;
  cin >> n;

  vector<int> v(n);
  read_arr(v, n);

  int m;
  cin >> m;

  vector<int> prefix(n + 1);
  for (int i = 1; i <= n; i++) {
    prefix[i] += prefix[i - 1] + v[i - 1];
  }

  sort(all(v));

  vector<int> prefix_sorted(n + 1);
  for (int i = 1; i <= n; i++) {
    prefix_sorted[i] += prefix_sorted[i - 1] + v[i - 1];
  }

  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      cout << prefix[r] - prefix[l - 1] << '\n';
    } else {
      cout << prefix_sorted[r] - prefix_sorted[l - 1] << '\n';
    }
  }
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
#else
  solve();
#endif

  return 0;
}
