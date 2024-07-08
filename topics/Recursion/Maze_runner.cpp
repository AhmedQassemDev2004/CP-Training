#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS false


void solve(int tc) {
    int n;
    cin >> n;

    vector <vector<char>> a(10, vector<char>(10));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    cin >> x1 >> y1 >> x2 >> y2;

    map<pii, bool> visited;
    function<int(int, int)> calc = [&](int x, int y) {
        pii p = {x, y};
        if (x > n || x < 1 || y < 1 || y > n || a[x][y] == '#' || visited[p]) {
            return 0ll;
        }

        if (x == x2 && y == y2) {
            return 1ll;
        }

        visited[p] = true;

        int ch1 = calc(x + 1, y); // down
        int ch2 = calc(x - 1, y); // up
        int ch3 = calc(x, y + 1); // right
        int ch4 = calc(x, y - 1); // left

        visited[p] = false;

        return ch1 + ch2 + ch3 + ch4;
    };

    cout << calc(x1, y1) << endl;
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