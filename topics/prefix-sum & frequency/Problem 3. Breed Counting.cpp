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

  vector<ll> one(n + 1), two(n + 1), three(n + 1);
  for (int i = 1; i <= n; i++) {
    one[i] = one[i - 1];
    two[i] = two[i - 1];
    three[i] = three[i - 1];

    ll temp;
    cin >> temp;

    if (temp == 1)
      one[i]++;
    else if (temp == 2)
      two[i]++;
    else if (temp == 3)
      three[i]++;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << one[r] - one[l - 1] << ' ' << two[r] - two[l - 1] << ' '
         << three[r] - three[l - 1] << '\n';
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
