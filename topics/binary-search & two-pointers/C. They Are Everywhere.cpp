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

auto solve() {
  int n;
  cin >> n;

  map<char, int> mp;
  string s;
  char c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    s.push_back(c);
    mp[c]++;
  }

  int distinct_size = mp.size();

  mp.clear();

  int left = 0, right = 0, ans = n;
  while (left < n) {
    while (right < n && mp.size() < distinct_size) {
      mp[s[right]]++;
      right++;
    }

    if (mp.size() == distinct_size)
      ans = min((int)(right - left), ans);

    if (mp[s[left]] == 1)
      mp.erase(s[left]);
    else
      mp[s[left]]--;
    left++;
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
