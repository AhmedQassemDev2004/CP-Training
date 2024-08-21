#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second

#define TESTS false

void solve(int tc) {
    int n;
    cin >> n;

    vector <vector<char>> a(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector <vector<bool>> visited(n + 1, vector<bool>(n + 1));
    function<int(int, int)> calc = [&](int x, int y) {
        if (x > n || x < 1 || y < 1 || y > n || a[x][y] == '#' || visited[x][y]) {
            return (int) 1e5;
        }

        if (x == x2 && y == y2) {
            return 0ll;
        }

        visited[x][y] = true;
        int ch1 = calc(x + 1, y) + 1; // down
        int ch2 = calc(x - 1, y) + 1; // up
        int ch3 = calc(x, y + 1) + 1; // right
        int ch4 = calc(x, y - 1) + 1; // left
        visited[x][y] = false;

        return (int) min({ch1, ch2, ch3, ch4});
    };

    int ans = calc(x1, y1);
    if (ans == 1e5 + 1) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
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