#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
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
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  read_arr(a, n);

  vector<int> c(n + 1);

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    c[l] += 1;
    c[r + 1] -= 1;
  }

  for (int i = 1; i < n; i++) {
    c[i] += c[i - 1];
  }

  sort(all(a));
  sort(all(c));

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * c[i + 1];
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
