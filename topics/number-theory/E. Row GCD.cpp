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

int gcd(int a, int b) {
  if (b > a)
    swap(a, b);

  if (b == 0)
    return a;

  return gcd(a % b, b);
}

auto solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);

  read_arr(a, n);

  sort(all(a));

  int _gcd = 0;
  for (int i = 1; i < n; i++) {
    _gcd = gcd(_gcd, a[i] - a[0]);
  }
  while (m--) {
    int b;
    cin >> b;

    cout << gcd(b + a[0], _gcd) << ' ';
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
