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

#define TESTS true

auto solve(int tc) {
    int n, s;
    cin >> n >> s;

    int max_sum = (n * (n + 1)) / 2;
    if (s > max_sum) {
        cout << -1 << '\n';
        return;
    }

    vector<int> result;
    for (int i = n; i > 0 && s > 0; --i) {
        if (s >= i) {
            result.push_back(i);
            s -= i;
        }
    }

    if (s != 0) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ' ';
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