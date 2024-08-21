#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// @formatter:off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second
// @formatter:on

#define TESTS 0
int n, m, ex, ey, sx, sy;
bool found = false;

bool rec(vector <vector<char>> &a, vector <vector<bool>> &visited, int i, int j) {
    if (i <= 0 || i > n || j <= 0 || j > m || visited[i][j] || a[i][j] == '*') {
        return false;
    }

    if (a[i][j] == 'E') {
        found = true;
        return true;
    }

    visited[i][j] = true;

    if (rec(a, visited, i + 1, j) || rec(a, visited, i - 1, j) ||
        rec(a, visited, i, j + 1) || rec(a, visited, i, j - 1)) {
        return true;
    }

    visited[i][j] = false;
    return false;
}

auto solve(int tc) {
    cin >> n >> m;

    vector <vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            cin >> a[i][j];

            if (a[i][j] == 'S') {
                sx = i, sy = j;
            } else if (a[i][j] == 'E') {
                ex = i, ey = j;
            }
        }
    }

    vector <vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    bool ans = rec(a, visited, sx, sy);

    cout << (ans ? "YES" : "NO") << endl;
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
