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

#define TESTS 0

void solve(int tc) {
    int n; // number of days
    cin >> n;

    int a[n][3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    vector <vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
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