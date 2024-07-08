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

auto solve() {
  string t, p;
  cin >> t >> p;

  vector<int> index(t.size());
  read_arr(index, (int)t.size());

  int ans = 0;

  auto good = [&](int mid) {
    string temp;
    temp.assign(t);

    for (int i = 0; i < mid; i++) {
      /* auto it = temp.begin() + (index[i] - 1); */
      /* temp.erase(it); */

      temp[index[i] - 1] = '-';
    }

    int i = 0;
    for (auto c : temp) {
      if (c == p[i])
        i++;
    }

    if (i == (int)p.size()) {
      ans = mid;
      return true;
    }

    return false;
  };

  int low = 1, high = t.size();

  while (low <= high) {
    int mid = (low + high) / 2;

    if (good(mid)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << ans;
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
