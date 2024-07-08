#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS true

// O(cbrt(n))
auto solve(int tc) {
  int x;
  cin >> x;

  int l = 1, r = cbrt(x);
  while (l <= r) {
    int res = pow(l, 3) + pow(r, 3);
    if (res == x) {
      cout << "YES\n";
      return;
    }

    if (res > x) {
      r--;
    } else {
      l++;
    }
  }

  cout << "NO\n";
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
