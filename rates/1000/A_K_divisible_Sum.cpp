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

#define TESTS true

auto solve(int tc) {
    int n, k;
    cin >> n >> k;

    if (n % k == 0) {
        cout << 1 << '\n';
    } else if (n == 1) {
        cout << k << '\n';
    } else if (k % n == 0) {
        cout << k / n << '\n';
    } else if (n > k) {
        cout << 2 << '\n';
    } else {
        cout << (k / n) + 1 << '\n';
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