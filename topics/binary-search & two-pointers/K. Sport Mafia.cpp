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

int sum(int x) { return x * x + 1 / 2; }

auto solve(int tc) {
  int n, k;
  cin >> n >> k;

  // n => number of moves alya did
  // k => number of candies in the box at the end

  int l = 1, r = 2e9, ans = 0;

  function<bool(int)> valid = [&](int put) {
    int i = 1, res = 0, cnt = 0;
    while (res < put) {
      res += i++;
      cnt++;
    }

    int rem = put - (n - cnt);

    if (rem >= k) {
      ans = n - cnt;
      return true;
    }

    return false;
  };

  while (l <= r) {
    int mid = (l + r) / 2;

    if (valid(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans;
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
