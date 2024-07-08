#include <algorithm>
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

#define TESTS true

auto solve() {
  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  while (q--) {
    int l, r;
    char c;
    cin >> l >> r >> c;

    int number_of_times = (r - (r % n)) / n;

    string res_str;
    while (number_of_times--) {
      res_str.append(s);
    }

    for (int i = 0; i < r % n; i++) {
      res_str += s[i];
    }

    res_str.erase(0, l - 1);

    sort(all(res_str));

    int start = lower_bound(all(res_str), c) - res_str.begin();
    int end = upper_bound(all(res_str), c) - res_str.begin();

    cout << end - start << '\n';
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
