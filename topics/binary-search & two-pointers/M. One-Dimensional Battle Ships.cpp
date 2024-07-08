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
const int N =1e7+7;
// clang-format on

#define TESTS false

auto solve(int tc) {
  int n, k, a;
  cin >> n >> k >> a;

  int m;
  cin >> m;

  vector<int> shots(m + 1);
  for (int i = 1; i <= m; i++)
    cin >> shots[i];

  auto valid = [&](int mid) {
    bitset<N> miss;
    for (int i = 1; i <= mid; i++) {
      miss[shots[i]] = true;
    }

    int total = 0, cells = 0, i = 1;
    while (i <= n) {
      if (miss[i] == false) {
        cells++;
      } else {
        cells = 0;
      }

      if (cells == a) {
        total++, cells = 0, i++;
      }
      i++;
    }

    return total < k;
  };

  int l = 1, r = m, ans = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (valid(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << ans;
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
