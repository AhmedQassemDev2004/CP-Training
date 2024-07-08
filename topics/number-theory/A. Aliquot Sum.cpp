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

set<int> divisors(int n) {
  set<int> res;

  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.insert(i);
      res.insert(n / i);
    }
  }

  res.erase(n);

  return res;
}

auto solve() {
  int n;
  cin >> n;

  while (n--) {
    int temp;
    cin >> temp;

    set<int> st = divisors(temp);

    int sum = accumulate(all(st), 0);
    if (sum > temp) {
      cout << "abundant\n";
    } else if (sum < temp) {
      cout << "deficient\n";
    } else {
      cout << "perfect\n";
    }
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
