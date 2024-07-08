#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve(int tc) {
  int n, s;
  cin >> n >> s;

  auto is_valid = [&](int x) {
    int sum = 0;
    int temp = x;
    while (x > 0) {
      int digit = x % 10;
      x /= 10;
      sum += digit;
    }
    return temp - sum >= s;
  };

  int l = 10, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (is_valid(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }

  if (ans == -1) {
    cout << 0;
  } else {
    cout << n - ans + 1;
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
