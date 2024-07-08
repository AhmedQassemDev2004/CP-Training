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
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve() {
  int a, b, c;
  cin >> a >> b >> c;

  int m;
  cin >> m;

  vector<pair<int, string>> arr(m);
  for (auto &it : arr)
    cin >> it.f >> it.s;

  sort(all(arr));

  int num = 0, total = 0;
  for (auto &it : arr) {
    if (!a && !b && !c)
      break;

#define add num++, total += it.f

    if (it.s == "USB" && a) {
      add, a--;
    } else if (it.s == "PS/2" && b) {
      add, b--;
    } else if (c) {
      add, c--;
    }
  }

  cout << num << ' ' << total << '\n';
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
