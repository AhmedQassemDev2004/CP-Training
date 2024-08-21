#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second

#define TESTS true

auto solve(int tc) {
    int h, w;
    cin >> h >> w;

    vector <vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector <vector<int>> dp(h, vector<int>(w));
    for (int i = 0; i < w; ++i) {
        dp[0][i] = a[0][i];
    }

    for (int i = 1; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j + 1 < w) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
            if (j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);

            dp[i][j] += a[i][j];
        }
    }

    int _max = 0;
    for (int i = 0; i < w; ++i) {
        _max = max(_max, dp[h - 1][i]);
    }

    cout << _max << '\n';
}

signed main() {
    FAST_IO

#if TESTS
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        solve(tc + 1);
    }
#else
    solve(1);
#endif

    return 0;
}