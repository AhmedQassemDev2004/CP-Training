#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve(int tc) {
  int n;
  cin >> n;

  vector<int> arr(n);
  read_arr(arr, n);

  sort(all(arr));

  vector<int> prefix(n + 1);
  vector<int> sum(n + 1);
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + arr[i - 1];
    sum[i] = sum[i - 1] + 1;
  }

  int q;
  cin >> q;

  while (q--) {
    int p;
    cin >> p;

    if (p >= arr[n - 1]) {
      cout << n << ' ' << prefix[n] << '\n';
      continue;
    }

    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (p >= arr[mid]) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    if (ans != -1) {
      cout << sum[ans] + 1 << ' ' << prefix[ans + 1] << '\n';
    } else {
      cout << -1 << '\n';
    }
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
