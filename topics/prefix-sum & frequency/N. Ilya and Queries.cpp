#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr, n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define f first
#define s second

#define TESTS false

auto solve() {
    string s;
    cin >> s;

    int n = s.size();

    int m;
    cin >> m;


    vector<bool> is_ok(n, false);
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i + 1]) {
            is_ok[i] = true;
        }
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + is_ok[i];
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        r--, l--;
        cout << prefix[r] - prefix[l] << '\n';
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
