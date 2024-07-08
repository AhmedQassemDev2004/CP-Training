#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define ll long long
#define ld long double
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define all(v) v.begin(), v.end()
#define read_arr(arr, n) for(ll i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(ll i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
// clang-format on

#define TESTS false

void solve() {
  ll n, q;
  cin >> n >> q;

  vector<ll> arr(n);
  read_arr(arr, n);

  vector<ll> prefix(n + 1);

  for (int i = 0; i <= n; ++i) {
    prefix[i + 1] = prefix[i] + arr[i];
  }

  while (q--) {
    ll first, second;
    cin >> first >> second;

    cout << prefix[second] - prefix[first] << '\n';
  }
}

int main() {
  FAST_IO

#if TESTS
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
#else
  solve();
#endif

  return 0;
}
