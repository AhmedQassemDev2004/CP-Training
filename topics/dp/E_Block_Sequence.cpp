#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second

#define TESTS true

auto solve(int tc) {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    function<int(int)> rec = [&](int i) {
        if (i == n)
            return (int) 0;
        if (dp[i] != -1) return dp[i];
        int leave = rec(i + 1) + 1;
        int take = (int) 1e9;
        if (i + a[i] + 1 <= n) take = rec(i + a[i] + 1);
        return dp[i] = min(take, leave);
    };

    cout << rec(0) << '\n';
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