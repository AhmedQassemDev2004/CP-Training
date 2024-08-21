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

#define TESTS false

auto solve(int tc) {
    string s1, s2;
    cin >> s1 >> s2;

    vector <vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));

    function<int(int, int)> rec = [&](int i = 0, int j = 0) {
        if (i == s1.size() || j == s2.size()) {
            return 0ll;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = rec(i + 1, j + 1) + 1;
        }

        return dp[i][j] = max(rec(i + 1, j), rec(i, j + 1));
    };

    cout << rec(0, 0);
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