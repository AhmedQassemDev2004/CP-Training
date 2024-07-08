#include <bits/stdc++.h>
using namespace std;

// clang-format off
long long temp;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define ln '\n'
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){cin>>temp;st.insert(temp);}
#define f first
#define s second
// clang-format on

#define TESTS false

auto solve() {
  int n, x;
  cin >> n >> x;

  vector<int> arr(n);
  read_arr(arr, n);

  sort(all(arr));

  int i = 0, j = n - 1;

  map<int, bool> have_gondola;

  int ans = 0;
  while (i < j) {
    if (arr[i] + arr[j] > x) {
      j--;
    } else {
      ++ans;
      have_gondola[i] = true;
      have_gondola[j] = true;
      i++;
      j--;
    }
  }

  ans += n - have_gondola.size();

  cout << ans << '\n';
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
