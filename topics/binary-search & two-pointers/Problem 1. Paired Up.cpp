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

bool cmp(pair<int, int> p1, pair<int, int> p2) { return p1.second < p2.second; }

auto solve() {
  int n;
  cin >> n;

  vector<pair<int, int>> arr(n); // {x: type, y: output}

  for (int i = 0; i < n; i++) {
    cin >> arr[i].f >> arr[i].s;
  }

  sort(all(arr), cmp);

  int left = 0, right = n - 1, sum = 0;
  while (left <= right) {
    sum = max(arr[left].s + arr[right].s, sum);

    arr[left].f--;
    arr[right].f--;

    if (arr[left].f == 0)
      left++;
    if (arr[right].f == 0)
      right--;
  }

  cout << sum;
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
