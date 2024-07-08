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
#define f first
#define s second
// clang-format on

#define TESTS false

// sort by ending time
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.s < b.s;
}

auto solve() {
  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  for (auto& it : arr) {
    cin >> it.f >> it.s;
  }

  sort(all(arr), cmp);

  int prev = 0, count = 0;
  for (auto it : arr) {
    if (it.f >= prev) {
      count++;
      prev = it.s;
    }
  }

  cout << count;
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
