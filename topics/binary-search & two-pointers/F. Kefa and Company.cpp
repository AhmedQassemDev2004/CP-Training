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
  int n, d;
  cin >> n >> d;

  vector<pii> a(n);
  for (auto &it : a)
    cin >> it.f >> it.s; // f=>money, s=>friendship

  sort(all(a));

  int l = 0, r = 0, _max = 0, sum = 0;
  while (l < n) {
    while (r < n && a[r].f - a[l].f < d) {
      sum += a[r].s;
      r++;
    }

    _max = max(sum, _max);

    sum -= a[l].s;
    l++;
  }

  _max = max(_max, sum);

  cout << _max;
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
