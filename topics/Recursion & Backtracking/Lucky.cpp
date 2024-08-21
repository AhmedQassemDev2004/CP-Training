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

int n;

int lucky(int p = 0, int idx = 0) {
    if (p > n) return 0;

    if (p == n) {
        return idx;
    }

    int ch1 = lucky(p * 10 + 4, 2 * idx + 1);
    int ch2 = lucky(p * 10 + 7, 2 * idx + 2);

    return max(ch1, ch2);
}

auto solve(int tc) {
    cin >> n;

    cout << lucky();
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