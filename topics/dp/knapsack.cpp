#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second

auto solve(int tc) {
    int n, c;
    cin >> n >> c;

    vector<int> w(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> p[i];
    }

    vector<int> dp(c + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = c; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
        }
    }

    cout << dp[c];
}

signed main() {
    FAST_IO

    solve(1);

    return 0;
}
