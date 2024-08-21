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

int max_sum(vector <vector<int>> a, int n, int m, int i = 0, int j = 0) {
    if (i >= n || j >= m) {
        return INT_MIN;
    }

    if (i == n - 1 && j == m - 1) {
        return a[i][j];
    }

    int down = max_sum(a, n, m, i + 1, j);
    int right = max_sum(a, n, m, i, j + 1);

    return max(down, right) + a[i][j];
}

auto solve(int tc) {
    int n, m;
    cin >> n >> m;

    vector <vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << max_sum(a, n, m);
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