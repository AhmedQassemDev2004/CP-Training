#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// @formatter:off
int next(){int x;cin>>x;return x;}
string snext(){string x;cin>>x;return x;}
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read_arr(arr) for(auto &it: arr) cin>>it;
#define pii pair<int, int>
#define f first
#define s second
// @formatter:on

#define TESTS true

auto solve(int tc) {
    int n = next(), m = next();

    vector <vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = next();
        }
    }

    auto valid = [&](int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    };

    auto can_decrement = [&](int i, int j) {
        int min_side = LONG_LONG_MAX;
        if ((valid(i + 1, j) && a[i][j] <= a[i + 1][j]) ||
            (valid(i - 1, j) && a[i][j] <= a[i - 1][j]) ||
            (valid(i, j + 1) && a[i][j] <= a[i][j + 1]) ||
            (valid(i, j - 1) && a[i][j] <= a[i][j - 1])) {
            return 0ll;
        }

        if (valid(i + 1, j)) min_side = min(min_side, a[i][j] - a[i + 1][j]);
        if (valid(i - 1, j)) min_side = min(min_side, a[i][j] - a[i - 1][j]);
        if (valid(i, j + 1)) min_side = min(min_side, a[i][j] - a[i][j + 1]);
        if (valid(i, j - 1)) min_side = min(min_side, a[i][j] - a[i][j - 1]);

        return (min_side == LONG_LONG_MAX ? 1 : min_side);
    };

    bool done;
    do {
        done = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int p = can_decrement(i, j);
                if (p) {
                    a[i][j] -= p;
                    done = false;
                }
            }
        }

    } while (!done);

    for (const auto &row: a) {
        for (const auto &x: row) {
            cout << x << ' ';
        }
        cout << '\n';
    }
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