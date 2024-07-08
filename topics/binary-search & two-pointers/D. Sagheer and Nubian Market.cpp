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
  int n, s;
  cin >> n >> s;

  vector<int> arr(n);
  read_arr(arr, n);

  int l = 1, r = n;
  int ans = 0, ans_cost = 0;

  auto good = [&](int mid) {
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      c[i] = arr[i] + mid * (i + 1);
    }

    sort(all(c));

    int sum = 0;
    for (int i = 0; i < mid; i++) {
      sum += c[i];
    }

    if (sum <= s) {
      ans_cost = sum;
      ans = mid;
      return true;
    }

    return false;
  };

  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (good(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << ans << ' ' << ans_cost;
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
