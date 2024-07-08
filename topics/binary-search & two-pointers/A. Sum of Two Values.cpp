#include <algorithm>
#include <bits/stdc++.h>
#include <pthread.h>
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

// Solution using binary search
auto solve() {
  int n, k;
  cin >> n >> k;

  vector<pii> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].f;
    arr[i].s = i + 1;
  }

  sort(all(arr));

  for (int i = 0; i < n; i++) {
    int l = 0, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;

      if (arr[mid].f == k - arr[i].f) {
        cout << arr[i].s << ' ' << arr[mid].s << '\n';
        return;
      }

      if (arr[mid].f > k - arr[i].f) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }

  cout << -1 << '\n';
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
