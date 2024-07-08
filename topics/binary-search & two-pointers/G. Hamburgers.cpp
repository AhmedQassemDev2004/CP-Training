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
  string s;
  cin >> s;

  map<char, int> count;
  map<int, char> mp = {{0, 'B'}, {1, 'S'}, {2, 'C'}};

  for (auto c : s) {
    count[c]++;
  }

  vector<int> n(3), p(3);
  read_arr(n, 3);
  read_arr(p, 3);

  int r;
  cin >> r;

  int ans = 0;

  auto good = [&](int mid) {
    int temp = r;
    for (int i = 0; i < 3; i++) {
      int need = mid * count[mp[i]];
      if (need > n[i]) {
        temp -= (need - n[i]) * p[i];
      }
    }

    if (temp >= 0) {
      ans = mid;
      return true;
    }

    return false;
  };

  int low = 1, high = 2e12 + 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (good(mid)) {
      low = mid + 1;
      ans = mid;
      /* cout << mid << " good\n"; */
    } else {
      high = mid - 1;
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
