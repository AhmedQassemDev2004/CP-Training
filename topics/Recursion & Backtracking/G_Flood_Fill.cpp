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
int n, m, x, y;

void start(vector <vector<char>> &a, set <pii> &visited, int i, int j) {
//    cout << "IN i=" << i << " j=" << j << " a[i][j]: " << a[i][j] << '\n';
    if (i <= 0 || i > n || j <= 0 || j > m || visited.count({i, j}) || a[i][j] == '*') {
        return;
    }

    visited.insert({i, j});
    start(a, visited, i + 1, j);
    start(a, visited, i - 1, j);
    start(a, visited, i, j + 1);
    start(a, visited, i, j - 1);

}

auto solve(int tc) {
    cin >> n >> m;

    vector <vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    cin >> x >> y;

    set <pii> visited;
    start(a, visited, x, y);
    cout << visited.size() << '\n';
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