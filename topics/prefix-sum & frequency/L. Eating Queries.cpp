#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS true

auto solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  read_arr(a, n);

  /* sort(all(a), greater<int>()); */
  sort(rall(a));

  vector<int> prefix(n);
  prefix[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefix[i] += prefix[i - 1] + a[i];
  }

  /* print_arr(prefix, n); */

  while (q--) {
    int x;
    cin >> x;

    /* auto it = lower_bound(all(prefix), x); */
    /**/
    /* if (it == prefix.end()) { */
    /*   cout << -1 << '\n'; */
    /* } else { */
    /*   cout << it - prefix.begin() + 1 << '\n'; */
    /* } */

    // Solution using binary-search

    if (prefix[n - 1] < x) {
      cout << -1 << '\n';
      continue;
    }

    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;

      if (prefix[mid] >= x) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    cout << ans + 1 << '\n';
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
