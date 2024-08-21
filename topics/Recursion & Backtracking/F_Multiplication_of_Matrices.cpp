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

#define TESTS false

int n1, n2, m1, m2;

void matrix_multiply(vector <vector<int>> &a, vector <vector<int>> &b, vector <vector<int>> &r, int x = 0, int y = 0) {
    if (x >= n1 || y >= m2) {
        return;
    }

    int res = 0;
    for (int i = 0; i < n2; ++i) {
        res += a[x][i] * b[y][i];
    }

    r[x][y] = res;

    matrix_multiply(a, b, r, x, y + 1);
    matrix_multiply(a, b, r, x + 1, y);
}

auto solve(int tc) {
    cin >> n1 >> m1;

    // NOTE: n1==m2

    vector <vector<int>> a(n1, vector<int>(m1));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cin >> a[i][j];
        }
    }

    cin >> n2 >> m2;

    vector <vector<int>> b(n2, vector<int>(m2));
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m1; j++) {
            cin >> b[i][j];
        }
    }

    vector <vector<int>> r(n1, vector<int>(m2)); // result matrix

    matrix_multiply(a, b, r);

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            cout << r[i][j] << ' ';;
        }
        cout << endl;
    }
}

int32_t main() {
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