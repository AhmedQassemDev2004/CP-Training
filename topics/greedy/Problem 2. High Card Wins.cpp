#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define ln '\n'
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) for(int i=0;i<n;i++){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve() {
  int n;
  cin >> n;

  set<int> a, b;
  read_set(a, n);

  for (int i = 1; i < (2 * n); i++) {
    if (a.find(i) == a.end())
      b.insert(i);
  }

  int ans = 0;
  for (auto x : a) {
    auto it = b.upper_bound(x);
    if (it != b.end()) {
      ans++;
      b.erase(it);
    }
  }

  cout << ans;
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
