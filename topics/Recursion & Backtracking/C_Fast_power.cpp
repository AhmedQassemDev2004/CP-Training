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

const int mod = 1000000007;

int ans(int base, int exp) {
    if (exp == 0) {
        return 1;
    }

    int half = ans(base, exp / 2);
    int half_squared = (half * half) % mod;

    if (exp % 2 != 0) {
        return (half_squared * base) % mod;
    } else {
        return half_squared;
    }
}

auto solve(int tc) {
    int n, m;
    cin >> n >> m;

    int res = ans(n % mod, m);
    cout << res << '\n';
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