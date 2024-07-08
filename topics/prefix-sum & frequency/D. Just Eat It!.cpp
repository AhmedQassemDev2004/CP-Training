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

#define TESTS true

auto solve() {
  int n;
  cin >> n;

  int total = 0;
  vector<int> a(n);
  for (auto& it : a) {
    cin >> it;
    total += it;
  }

  int sum = INT_MIN, ans = 0, max_count = 0, current_max_count = 0;
  for (int i = 0; i < n; i++) {
    if (sum < 0) {
      sum = 0;
    }

    sum += a[i];
    current_max_count++;

    if (sum > ans) {
      max_count = max(current_max_count, max_count);
      ans = sum;
    }
  }

  if (ans < total || max_count == n)
    cout << "YES\n";
  else
    cout << "NO\n";
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
